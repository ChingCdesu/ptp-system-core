/**
 * @file logger_impl.cc
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 日志模块实现
 * @version 0.1
 * @date 2021-08-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "logger_impl.h"

namespace ptp {
namespace module {

PATTERN_SINGLETON_IMPLEMENT(Logger);

Logger::~Logger() {}

Logger::Logger() {}

RC Logger::Start() {
#ifndef NDEBUG
  spdlog::default_logger()->set_level(spdlog::level::trace);
#endif
  return RC::SUCCESS;
}

RC Logger::Stop() { return RC::SUCCESS; }

}  // namespace module
}  // namespace ptp