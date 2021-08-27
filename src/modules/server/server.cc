#include "server.h"

namespace ptp {
namespace module {
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
  return RC::SUCCESS;
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