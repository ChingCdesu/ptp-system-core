/**
 * @file module.cc
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 模块函数实现
 * @version 0.1
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "module.h"

namespace ptp {
namespace common {
ReturnCode StartModule(Module& interface) {
  auto future =
      std::async(std::launch::async, [&] { return interface.Start(); });
  auto status = future.wait_for(5s);
  if (std::future_status::ready == status) {
    return future.get();
  } else if (std::future_status::timeout == status) {
    PTP_WARNING("Startup module: {}-{} timeout", interface.GetName(),
                interface.GetVersion());
    return TIMEOUT;
  } else {
    return FAILURE;
  }
}

ReturnCode StopModule(Module& interface) {
  auto future =
      std::async(std::launch::async, [&] { return interface.Stop(); });
  auto status = future.wait_for(5s);
  if (std::future_status::ready == status) {
    return future.get();
  } else if (std::future_status::timeout == status) {
    PTP_WARNING("Shutdown module: {}-{} timeout", interface.GetName(),
                interface.GetVersion());
    return TIMEOUT;
  } else {
    return FAILURE;
  }
}

}  // namespace common
}  // namespace ptp