/**
 * @file condition.h
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__CONDITION_H
#define PTP__CONDITION_H

#include <drogon/orm/Criteria.h>

namespace ptp::common {
using Criteria = drogon::orm::Criteria;

void ConditionAnd(Criteria& cond1, const Criteria& cond2);
void ConditionOr(Criteria& cond1, const Criteria& cond2);
}  // namespace ptp::common

#endif