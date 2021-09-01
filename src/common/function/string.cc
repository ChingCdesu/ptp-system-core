/**
 * @file string.cc
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "string.h"

namespace ptp::common {
std::vector<std::string> str_split(const std::string& str,
                                   const std::string& delimiter) {
  size_t pos = 0;
  std::vector<std::string> result;
  do {
    size_t right = str.find(delimiter, pos);
    result.emplace_back(str.substr(pos, right - pos));
    pos = right + 1;
  } while (pos != 0);
  return result;
}

std::string str_join(const std::vector<std::string>& vec,
                     const std::string& delimiter) {
  std::string str;
  for (size_t index = 0; index < vec.size(); ++index) {
    str += vec.at(index);
    if (index != vec.size() - 1) {
      str += delimiter;
    }
  }
  return str;
}

bool isNumber(const std::string& str) {
  return str.end() == std::find_if_not(str.begin(), str.end(),
                                       [](char c) { return std::isdigit(c); });
}

uint32_t str2uint(const std::string& str, uint32_t defaultValue) {
  return isNumber(str) ? std::stoul(str) : defaultValue;
}
}  // namespace ptp::common