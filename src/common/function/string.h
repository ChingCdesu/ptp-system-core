/**
 * @file string.h
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__STRING_H
#define PTP__STRING_H
#include <algorithm>
#include <string>
#include <vector>

namespace ptp::common {
std::vector<std::string> str_split(const std::string& str,
                                   const std::string& delimiter);

std::string str_join(const std::vector<std::string>& vec,
                     const std::string& delimiter);

bool isNumber(const std::string& str);

uint32_t str2uint(const std::string& str, uint32_t defaultValue);

}  // namespace ptp::common

#endif