/**
 * @file logger_impl.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 日志模块声明，但此模块不属于ptp::common::Module的子类
 * @version 0.1
 * @date 2021-08-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__LOGGER_IMPL_H
#define PTP__LOGGER_IMPL_H

#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <fmt/core.h>

#include "common/enums/returns.h"
#include "common/macros/singleton.h"

namespace ptp {
namespace module {

class Logger {
  PATTERN_SINGLETON_DECLARE(Logger);

 private:

 public:
  RC Start();
  RC Stop();
};

}  // namespace module
}  // namespace ptp

#define g_Logger (*ptp::module::Logger::Instance())

#define PTP_TRACE(...) SPDLOG_TRACE(__VA_ARGS__)
#define PTP_DEBUG(...) SPDLOG_DEBUG(__VA_ARGS__)
#define PTP_INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define PTP_WARNING(...) SPDLOG_WARN(__VA_ARGS__)
#define PTP_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define PTP_FATAL(...) SPDLOG_CRITICAL(__VA_ARGS__)

#endif
