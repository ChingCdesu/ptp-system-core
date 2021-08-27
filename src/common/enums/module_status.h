/**
 * @file module_status.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 模块运行状态
 * @version 0.1
 * @date 2021-08-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__MODULE_STATUS_H
#define PTP__MODULE_STATUS_H

namespace ptp {
namespace common {
enum ModuleStatus {
  STOPING = 0,
  RUNNING = 1,
};
}  // namespace common
}  // namespace ptp

#endif