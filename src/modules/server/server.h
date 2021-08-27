/**
 * @file server.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief drogon服务器声明
 * @version 0.1
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PTP__SERVER_H
#define PTP__SERVER_H

#include <drogon/drogon.h>

#include <thread>
#include <chrono>
#include <future>

#include "common/enums/returns.h"
#include "common/macros/singleton.h"
#include "common/class/module.h"
#include "modules/logger/logger_impl.h"

namespace ptp {
namespace module {
class Server : public ptp::common::Module {
  PATTERN_SINGLETON_DECLARE(Server);

 private:
  std::thread thread_;
 public:
  RC Start() override;
  RC Stop() override;
};
}  // namespace module
}  // namespace ptp

#define g_serverImpl (*ptp::module::Server::Instance())

#endif