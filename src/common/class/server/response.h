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

Response success_res() {
  Json::Value res;
  res["code"] = 0;
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response success_res_with_data(const Json::Value& data) {
  Json::Value res;
  res["code"] = 0;
  res["obj"] = data;
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response incorrect_token_res() {
  Json::Value res;
  res["code"] = -6;
  res["prompt"] = "登录失效，请重新登录！";
#ifndef NDEBUG
  res["msg"] = "token验证失败";
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response login_failed_res() {
  Json::Value res;
  res["code"] = -7;
  res["prompt"] = "用户名或密码错误！";
#ifndef NDEBUG
  res["msg"] = "用户名或密码错误";
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response access_block_res() {
  Json::Value res;
  res["code"] = -8;
  res["prompt"] = "用户受限！";
#ifndef NDEBUG
  res["msg"] = "用户被管理员禁用";
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response db_failed_res(const std::string& err) {
  Json::Value res;
  res["code"] = -9;
  res["prompt"] = "未知错误！";
#ifndef NDEBUG
  res["msg"] = "[数据库错误] " + err;
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response user_not_found_res() {
  Json::Value res;
  res["code"] = -10;
  res["prompt"] = "指定用户不存在！";
#ifndef NDEBUG
  res["msg"] = "用户不存在";
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response invalid_argument_res(const std::string& field,
                              const std::string& type) {
  Json::Value res;
  res["code"] = -11;
  res["prompt"] = "参数类型错误！";
#ifndef NDEBUG
  res["msg"] = fmt::format(R"(字段"{}"应为"{}"类型)", field, type);
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response data_not_found_res() {
  Json::Value res;
  res["code"] = -12;
  res["prompt"] = "数据不存在！";
#ifndef NDEBUG
  res["msg"] = "获取主键数据时，没有数据";
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response req_data_validation_failed_res(const std::string& err) {
  Json::Value res;
  res["code"] = -13;
  res["prompt"] = "您提交的数据不符合规范！";
#ifndef NDEBUG
  res["msg"] = "[Json字段验证失败] " + err;
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response user_no_privilege_res() {
  Json::Value res;
  res["code"] = -14;
  res["prompt"] = "您没有该权限！";
#ifndef NDEBUG
  res["msg"] = "用户无权限";
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response json_error_res(const std::string& err) {
  Json::Value res;
  res["code"] = -15;
  res["prompt"] = "数据错误！";
#ifndef NDEBUG
  res["msg"] = "[Json解析失败] " + err;
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response admin_not_editable() {
  Json::Value res;
  res["code"] = -16;
  res["prompt"] = "您没有该权限！";
#ifndef NDEBUG
  res["msg"] = "管理员角色/用户不可修改！";
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

Response unknown_failed(const std::string& err) {
  Json::Value res;
  res["code"] = 1;
  res["prompt"] = "出现未知错误！";
#ifndef NDEBUG
  res["msg"] = "[未知错误] " + err;
#endif
  auto response = drogon::HttpResponse::newHttpJsonResponse(res);
  return response;
}

}  // namespace ptp::api::v1::response

#endif