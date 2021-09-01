/**
 * @file json.h
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <json/json.h>

#include <sstream>
#include <string>

#include "common/enums/returns.h"
#include "modules/logger/logger_impl.h"

namespace ptp::common {
RC json_parse(const std::string& str, Json::Value& data, std::string& err);
void jsonDecodeInlineString(Json::Value& json);
}  // namespace ptp::common
