/**
 * @file json.cc
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "json.h"

namespace ptp::common {
RC json_parse(const std::string& str, Json::Value& data, std::string& err) {
  std::stringstream ss(str);
  Json::CharReaderBuilder builder;
  bool success = Json::parseFromStream(builder, ss, &data, &err);
  if (!success) {
    return FAILURE;
  }
  return SUCCESS;
}

void jsonDecodeInlineString(Json::Value& json) {
  if (json.isObject()) {
    for (const auto& mem : json.getMemberNames())
      jsonDecodeInlineString(json[mem]);
  }

  if (json.isArray()) {
    for (auto& item : json) jsonDecodeInlineString(item);
  }

  if (json.isString()) {
    Json::Value value(Json::Value::nullRef);
    std::string err;
    json_parse(json.asString(), value, err);
    if (value.isObject() || value.isArray()) json = value;
  }
}
}  // namespace ptp::common