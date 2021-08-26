/**
 * @file logger_impl.cc
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-08-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "logger_impl.h"


INITIALIZE_EASYLOGGINGPP

namespace ptp {
namespace module {

PATTERN_SINGLETON_IMPLEMENT(Logger);

Logger::~Logger() {}

Logger::Logger() {}

RC Logger::Start() {
  el::Configurations conf;
  conf.setToDefault();
  conf.setGlobally(el::ConfigurationType::MillisecondsWidth, "6");
  conf.setGlobally(el::ConfigurationType::Format, "%datetime %level %fbase:%line -- %msg");
  el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
  el::Loggers::reconfigureLogger("default", conf);
  status_ = ptp::common::RUNNING;
  return RC::SUCCESS;
}

RC Logger::Stop() {
  return RC::SUCCESS;
}

}  // namespace module
}  // namespace ptp