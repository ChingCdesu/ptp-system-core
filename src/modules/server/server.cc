/**
 * @file server.cc
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief drogon服务器实现
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
  drogon::app().registerHandler(
      "/",
      [](const drogon::HttpRequestPtr&,
         std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setBody("Hello, World!");
        callback(resp);
      },
      {drogon::Get});
  thread_ = std::thread([] {
    PTP_INFO("server startup on http://127.0.0.1:8848");
    drogon::app().addListener("127.0.0.1", 8848).run();
  });
  auto task = std::async(std::launch::async, [this] {
    while (!drogon::app().isRunning());
    status_ = ptp::common::RUNNING;
  });
  auto task_status = task.wait_for(10s);
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
}  // namespace module
}  // namespace ptp