/**
 * @file module.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief Base Module Class
 * @version 0.1
 * @date 2021-08-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__MODULE_H
#define PTP__MODULE_H

#include <chrono>
#include <future>
#include <string>

#include "common/enums/module_status.h"
#include "common/enums/returns.h"
#include "modules/logger/logger_impl.h"

using namespace std::chrono_literals;
namespace ptp {
namespace common {

class Module {
 protected:
  ModuleStatus status_ = STOPING;
  std::string name_;
  std::string version_;

 protected:
  Module() {}

 public:
  virtual ReturnCode Start() = 0;
  virtual ReturnCode Stop() = 0;
  std::string GetName() { return name_; }
  std::string GetVersion() { return version_; }
  ModuleStatus GetStatus() { return status_; }

  virtual ~Module() {}
};

ReturnCode StartModule(Module& interface);

ReturnCode StopModule(Module& interface);

}  // namespace common
}  // namespace ptp

#endif