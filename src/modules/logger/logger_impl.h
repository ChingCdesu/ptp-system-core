/**
 * @file logger_impl.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__LOGGER_IMPL_H
#define PTP__LOGGER_IMPL_H

#include <easylogging++.h>
#include <fmt/core.h>

#include "common/enums/returns.h"
#include "common/macros/singleton.h"
#include "common/module.h"

namespace ptp {
namespace module {

class Logger : public ptp::common::Module {
  PATTERN_SINGLETON_DECLARE(Logger);

 public:
  RC Start() override;
  RC Stop() override;
};

}  // namespace module
}  // namespace ptp

#define g_LoggerImpl (*ptp::module::Logger::Instance())

#define PTP_VERBOSE(...) LOG(VERBOSE) << fmt::format(__VA_ARGS__)
#define PTP_TRACE(...) LOG(TRACE) << fmt::format(__VA_ARGS__)
#define PTP_DEBUG(...) LOG(DEBUG) << fmt::format(__VA_ARGS__)
#define PTP_INFO(...) LOG(INFO) << fmt::format(__VA_ARGS__)
#define PTP_WARNING(...) LOG(WARNING) << fmt::format(__VA_ARGS__)
#define PTP_ERROR(...) LOG(ERROR) << fmt::format(__VA_ARGS__)
#define PTP_FATAL(...) LOG(FATAL) << fmt::format(__VA_ARGS__)

#endif
