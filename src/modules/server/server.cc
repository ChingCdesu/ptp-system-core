/**
 * @file server.cc
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 服务器类实现
 * @version 0.1
 * @date 2021-08-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "server.h"

namespace ptp {
namespace module {

using namespace std::chrono_literals;

PATTERN_SINGLETON_IMPLEMENT(Server);

Server::Server() {
  name_ = "drogon-server";
  version_ = "0.1.0";
}
Server::~Server() {}

RC Server::Start() {
  drogon::app()
      .createDbClient("mysql", "127.0.0.1", 3306, "ptp_system", "root",
                      "ChingC.local1")
      .registerSyncAdvice([this](const drogon::HttpRequestPtr& req) {
        std::lock_guard<std::mutex> lock(mutex_);
        const auto remoteIp = req->getPeerAddr().toIp();
        const auto now = std::chrono::system_clock::now();
        const auto now_s = std::chrono::duration_cast<std::chrono::seconds>(
                               now.time_since_epoch())
                               .count();
        if (request_limit_.count(remoteIp) == 0) {
          request_limit_.emplace(remoteIp, std::queue<int64_t>());
        }
        auto& queue = request_limit_[remoteIp];
        queue.emplace(now_s);
        if (queue.size() > 10) {
          if (queue.back() - queue.front() < 10) {
            PTP_WARNING("IP \"{}\" 在10s内发出过多请求", remoteIp);
          }
          queue.pop();
        }
        return nullptr;
      })
      .registerPreRoutingAdvice([](const drogon::HttpRequestPtr& req) {
        req->addHeader("request_id", std::to_string(++request_id_));
        PTP_INFO("request {}: {} - - {} {} \nUser-Agent: {}", request_id_,
                 req->getPeerAddr().toIp(), req->getMethodString(),
                 req->getPath(), req->getHeader("User-Agent"));
      })
      .registerPostHandlingAdvice([](const drogon::HttpRequestPtr& req,
                                     const drogon::HttpResponsePtr& res) {
        PTP_INFO("response {}: {} - {} bytes", req->getHeader("request_id"),
                 res->getStatusCode(), res->getBody().length());
      })
      .addListener("127.0.0.1", 9000);
  thread_ = std::thread([] {
    PTP_INFO("server startup on http://127.0.0.1:9000");
    drogon::app().run();
  });
  auto launch = std::async(std::launch::async, [this] {
    while (!drogon::app().isRunning())
      ;
    status_ = ptp::common::RUNNING;
  });
  auto task_status = launch.wait_for(10s);
  bool running = false;
  RC rc;
  if (std::future_status::ready == task_status) {
    rc = drogon::app().isRunning() ? RC::SUCCESS : RC::FAILURE;
  } else {
    rc = RC::TIMEOUT;
  }
  return rc;
}

RC Server::Stop() {
  status_ = ptp::common::STOPING;
  if (!thread_.joinable()) {
    status_ = ptp::common::FAILED;
    return RC::FAILURE;
  }
  drogon::app().quit();
  thread_.join();
  status_ = ptp::common::STOPPED;
  return RC::SUCCESS;
}
uint64_t Server::request_id_ = 0;
std::unordered_map<std::string, std::queue<int64_t>> Server::request_limit_{};
}  // namespace module
}  // namespace ptp