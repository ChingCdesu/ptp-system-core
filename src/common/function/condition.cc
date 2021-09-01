/**
 * @file condition.cc
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "condition.h"

namespace ptp::common {
  void ConditionAnd(Criteria& cond1, const Criteria& cond2) {
  if (cond1) {
    cond1 = cond1 && cond2;
  } else {
    cond1 = cond2;
  }
}

void ConditionOr(Criteria& cond1, const Criteria& cond2) {
  if (cond1) {
    cond1 = cond1 || cond2;
  } else {
    cond1 = cond2;
  }
}
}