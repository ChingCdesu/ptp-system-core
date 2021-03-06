/**
 * @file server.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 服务器类声明
 * @version 0.1
 * @date 2021-08-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__SERVER_H
#define PTP__SERVER_H

#include <drogon/drogon.h>

#include <chrono>
#include <future>
#include <queue>
#include <thread>
#include <unordered_map>

#include "common/class/module.h"
#include "common/enums/returns.h"
#include "common/macros/singleton.h"
#include "modules/logger/logger_impl.h"

namespace ptp {
namespace module {
class Server : public ptp::common::Module {
  PATTERN_SINGLETON_DECLARE(Server);

 private:
  std::thread thread_;
  static uint64_t request_id_;
  static std::unordered_map<std::string, std::queue<int64_t>> request_limit_;
  std::mutex mutex_;
 public:
  RC Start() override;
  RC Stop() override;
};
}  // namespace module
}  // namespace ptp

#define g_Server (*ptp::module::Server::Instance())

#endif
