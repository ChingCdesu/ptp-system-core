/**
 * @file url.h
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__URL_H
#define PTP__URL_H

#include <drogon/drogon.h>

#include <unordered_map>

#include "common/function/string.h"

namespace ptp::common {
std::unordered_map<std::string, std::string> url_query_parse(
    const std::string& query_str);
}  // namespace ptp::common

#endif