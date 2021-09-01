/**
 * @file url.cc
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "url.h"

namespace ptp::common {
std::unordered_map<std::string, std::string> url_query_parse(
    const std::string& query_str) {
  auto queries = str_split(query_str, "&");
  std::unordered_map<std::string, std::string> query_map;
  for (const auto& q : queries) {
    auto decoded = drogon::utils::urlDecode(q);
    auto pos = decoded.find_first_of('=');
    std::string key = decoded.substr(0, pos);
    std::string value = decoded.substr(pos + 1);
    query_map[key] = value;
  }
  return query_map;
}
}  // namespace ptp::common