/**
 * @file response.h
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__RESPONSE_H
#define PTP__RESPONSE_H

#include <drogon/HttpResponse.h>
#include <fmt/core.h>
#include <json/json.h>

#include "modules/logger/logger_impl.h"

namespace ptp::api::v1::response {
using Response = std::shared_ptr<drogon::HttpResponse>;

Response success_res();

Response success_res_with_data(const Json::Value& data);

Response incorrect_token_res();

Response login_failed_res();

Response access_block_res();

Response db_failed_res(const std::string& err);

Response user_not_found_res();

Response invalid_argument_res(const std::string& field,
                              const std::string& type);

Response data_not_found_res();

Response req_data_validation_failed_res(const std::string& err);

Response user_no_privilege_res();

Response json_error_res(const std::string& err);

Response admin_not_editable();

Response unknown_failed(const std::string& err);

}  // namespace ptp::api::v1::response

#endif