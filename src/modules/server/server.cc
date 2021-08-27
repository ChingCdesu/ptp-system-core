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
  name_ = "server";
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
  auto task = std::async(std::launch::async, [] {
    while (!drogon::app().isRunning()) {
      std::this_thread::sleep_for(1s);
    }
    return drogon::app().isRunning();
  });
  auto task_status = task.wait_for(10s);
  bool running = false;
  RC rc;
  if (std::future_status::ready == task_status) {
    running = task.get();
    rc = running ? RC::SUCCESS : RC::FAILURE;
  } else {
    rc = RC::TIMEOUT;
  }
  return rc;
}

RC Server::Stop() {
  if (!thread_.joinable()) {
    return RC::FAILURE;
  }
  drogon::app().quit();
  thread_.join();
  return RC::SUCCESS;
}
}  // namespace module
}  // namespace ptp