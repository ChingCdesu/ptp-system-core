/**
 * @file returns.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 返回值
 * @version 0.1
 * @date 2021-08-25
 *
 * @copyright Copyright (c) 2021
 */

#ifndef PTP__ENUMS_H
#define PTP__ENUMS_H

namespace ptp {
namespace common {

/**
 * @brief All function return code
 * 
 * @version 0.1
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @date 2021-08-25
 * @copyright Copyright (c) 2021
 */
enum ReturnCode {
  SUCCESS = 0,
  FAILURE = 1,
  TIMEOUT = 2,
};

}  // namespace common
}  // namespace ptp

typedef ptp::common::ReturnCode RC;

#endif
