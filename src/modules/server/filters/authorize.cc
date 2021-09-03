/**
 * @file authorize.cc
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-02
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "authorize.h"

#define AUTHORIZE_FAILED                               \
  res["msg"] = msg;                                    \
  res["prompt"] = prompt;                              \
  fcb(drogon::HttpResponse::newHttpJsonResponse(res)); \
  return

namespace ptp::api::v1 {
void AuthorizeFilter::doFilter(const drogon::HttpRequestPtr& req,
                               drogon::FilterCallback&& fcb,
                               drogon::FilterChainCallback&& fccb) {
  Json::Value res;
  res["code"] = 9;
  std::string msg{""}, prompt{""};
  if (!TimestampCheck(req, msg, prompt)) {
    AUTHORIZE_FAILED;
  }
  if (!SecretCheck(req, msg, prompt) && !TokenCheck(req, msg, prompt)) {
    AUTHORIZE_FAILED;
  }
  if (!PrivilegeCheck(req, msg, prompt)) {
    AUTHORIZE_FAILED;
  }
  fccb();
}

bool AuthorizeFilter::PrivilegeCheck(const drogon::HttpRequestPtr& req,
                                     std::string& msg, std::string& prompt) {
  // TODO
  return true;
}

bool AuthorizeFilter::TokenCheck(const drogon::HttpRequestPtr& req,
                                 std::string& msg, std::string& prompt) {
  const auto account = req->getHeader("Account");
  if (account.empty()) {
    PTP_DEBUG("Header: Account不存在");
    return false;
  }
  const auto token = req->getHeader("Token");
  if (token.empty()) {
    PTP_DEBUG("Header: Token不存在");
    return false;
  }
  const auto timestamp = req->getHeader("Timestamp");
  int32_t user_id;
  std::vector<UserMeta> uuids;
  {
    using namespace drogon::orm;
    Mapper<User> user(drogon::app().getDbClient());
    Mapper<UserMeta> user_meta(drogon::app().getDbClient());
    try {
      user_id = user.findOne(Criteria(User::Cols::_account, CompareOperator::EQ,
                                      account))
                    .getValueOfId();
    } catch (const drogon::orm::UnexpectedRows& ex) {
      PTP_ERROR("用户\"{}\"不存在", account);
      return false;
    }
    try {
      uuids = user_meta.findBy(
          Criteria(UserMeta::Cols::_relative_id, CompareOperator::EQ,
                   user_id) &&
          Criteria(UserMeta::Cols::_meta_name, CompareOperator::EQ, "UUID"));
    } catch (const drogon::orm::UnexpectedRows& ex) {
      PTP_ERROR("用户\"{}\"没有UUID", account);
      return false;
    }

    try {
      for (const auto& item : uuids) {
        // TODO: 制定UUID相关验证规范
        const auto uuid = item.getValueOfMetaValue();
        const auto calc = hmac<SHA256>(uuid, "auth" + timestamp);
        if (calc.compare(token) == 0) {
          return true;
        }
      }
    } catch (drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("DB Error: {}", ex.base().what());
    }
  }
  return false;
}

bool AuthorizeFilter::SecretCheck(const drogon::HttpRequestPtr& req,
                                  std::string& msg, std::string& prompt) {
  const auto auth = req->getHeader("Authorization");
  if (auth.empty()) {
    PTP_DEBUG("Header: Authorization不存在");
    return false;
  }
  if (auth.substr(0, 6).compare("Basic ") != 0) {
    PTP_ERROR("HTTP校验不是Basic Auth类型");
    return false;
  }
  const auto b64 = auth.substr(6);
  const auto raw = drogon::utils::base64Decode(b64);
  if (!ptp::common::isReadable(raw)) {
    PTP_ERROR("校验字符串不是合法的base64字符串");
    return false;
  }
  if (raw.find(':') == std::string::npos) {
    PTP_ERROR("解析失败，明文中username和password未用英文冒号分开");
    return false;
  }
  const auto account = raw.substr(0, raw.find(':'));
  const auto password = raw.substr(raw.find(':') + 1);
  std::string err;
  int32_t user_id;
  UserMeta obj_secrets;
  Json::Value secrets;
  {  // 获取数据
    using namespace drogon::orm;
    Mapper<User> user(drogon::app().getDbClient());
    Mapper<UserMeta> user_meta(drogon::app().getDbClient());
    try {
      user_id = user.findOne(Criteria(User::Cols::_account, CompareOperator::EQ,
                                      account))
                    .getValueOfId();
    } catch (const drogon::orm::UnexpectedRows& ex) {
      PTP_ERROR("用户\"{}\"不存在", account);
      return false;
    }
    try {
      obj_secrets = user_meta.findOne(
          Criteria(UserMeta::Cols::_relative_id, CompareOperator::EQ,
                   user_id) &&
          Criteria(UserMeta::Cols::_meta_name, CompareOperator::EQ, "API Key"));
    } catch (const drogon::orm::UnexpectedRows& ex) {
      PTP_ERROR("用户\"{}\"没有API Key", account);
      return false;
    }
    auto success = ptp::common::json_parse(obj_secrets.getValueOfMetaValue(),
                                           secrets, err);
    if (!err.empty()) {
      PTP_ERROR("json 解析失败, {}", err);
    }
    auto checker = [](const Json::Value& obj) {
      if (!obj.isArray()) {
        return false;
      }
      for (const auto& item : obj) {
        if (!item.isObject()) {
          return false;
        }
        if (!item.isMember("label") || !item["label"].isString()) {
          return false;
        }
        if (!item.isMember("key") || !item["key"].isString()) {
          return false;
        }
      }
      return true;
    };
    try {
      if (success != RC::SUCCESS || !checker(secrets)) {
        user_meta.deleteBy(Criteria(UserMeta::Cols::_relative_id,
                                    CompareOperator::EQ, user_id) &&
                           Criteria(UserMeta::Cols::_meta_name,
                                    CompareOperator::EQ, "API Key Backup"));
        UserMeta backup(obj_secrets.toJson());
        backup.setMetaName("API Key Backup");
        backup.setRelativeId(user_id);
        user_meta.insert(backup);
        obj_secrets.setMetaValue("[]");
        user_meta.update(obj_secrets);
        PTP_ERROR(
            "解析用户\"{}\"(id: {})的API Key时出现问题，已重置。原来的API "
            "key备份到\"API Key Backup\"中。",
            account, user_id);
        return false;
      }
      for (const auto& key : secrets) {
        // TODO: 制定API Key相关验证规范
        if (key["key"].asString().compare(password) == 0) {
          return true;
        }
      }
    } catch (drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("DB Error: {}", ex.base().what());
    }
  }
  return false;
}

bool AuthorizeFilter::TimestampCheck(const drogon::HttpRequestPtr& req,
                                     std::string& msg, std::string& prompt) {
  const auto headers = req->getHeaders();
  if (headers.find("Timestamp") == std::end(headers)) {
    prompt = "不合理的请求！";
#ifndef NDEBUG
    msg = "请求头必须存在时间戳Timestamp";
#endif
    return false;
  }
  const auto s_timestamp = headers.at("Timestamp");
  if (!ptp::common::isNumber(s_timestamp)) {
    prompt = "不合理的请求！";
#ifndef NDEBUG
    msg = "时间戳只能是非负整数";
#endif
    return false;
  }
  const auto timestamp = std::stoll(s_timestamp);
  const auto now = std::chrono::system_clock::now();
  const auto now_s =
      std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch())
          .count();
  PTP_DEBUG("用户时间戳: {}, 服务器时间戳: {}", timestamp, now_s);
  if (std::abs(timestamp - now_s) > 30) {
    prompt = "请求超时！";
#ifndef NDEBUG
    msg = "请求时间与服务器时间差超过30秒";
#endif
    return false;
  }
  return true;
}
}  // namespace ptp::api::v1