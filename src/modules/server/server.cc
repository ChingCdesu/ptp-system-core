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
}  // namespace module
}  // namespace ptp