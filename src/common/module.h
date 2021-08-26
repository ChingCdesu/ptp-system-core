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

#include <future>

#include "common/enums/module_status.h"
#include "common/enums/returns.h"

namespace ptp {
namespace common {

class Module {
 protected:
  ModuleStatus status_ = STOPING;

 protected:
  Module() {}

 public:
  virtual ReturnCode Start() = 0;
  virtual ReturnCode Stop() = 0;
  virtual ~Module() {}
};

}  // namespace common
}  // namespace ptp

#endif