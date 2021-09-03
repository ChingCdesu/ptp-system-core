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

#ifndef PTP__FILTER_AUTHORIZE_H
#define PTP__FILTER_AUTHORIZE_H

#include <drogon/HttpFilter.h>
#include <drogon/HttpResponse.h>
#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>

#include <chrono>
#include <string>

#include "common/crypto/hmac.h"
#include "common/crypto/sha256.h"
#include "common/function/json.h"
#include "common/function/string.h"
#include "modules/logger/logger_impl.h"
#include "modules/server/models/PtpUser.h"
#include "modules/server/models/PtpUserMeta.h"

namespace ptp::api::v1 {
using User = drogon_model::ptp_system::PtpUser;
using UserMeta = drogon_model::ptp_system::PtpUserMeta;

class AuthorizeFilter : public drogon::HttpFilter<AuthorizeFilter> {
 public:
  virtual void doFilter(const drogon::HttpRequestPtr& req,
                        drogon::FilterCallback&& fcb,
                        drogon::FilterChainCallback&& fccb) override;

 private:
  bool PrivilegeCheck(const drogon::HttpRequestPtr& req, std::string& msg,
                      std::string& prompt);
  bool TokenCheck(const drogon::HttpRequestPtr& req, std::string& msg,
                  std::string& prompt);

  /**
   * @brief 客户端使用API key进行访问（HTTP Basic Auth）
   *
   * @param req 原始请求
   * @param msg 调试消息
   * @param prompt 用户提示消息
   * @return true 校验通过
   * @return false 校验失败
   */
  bool SecretCheck(const drogon::HttpRequestPtr& req, std::string& msg,
                   std::string& prompt);

  /**
   * @brief 检测客户端时间与服务器时间差，如果时间差大于30s会拒绝请求
   *
   * @param req 原始请求
   * @param msg 调试消息
   * @param prompt 用户提示消息
   * @return true 校验通过
   * @return false 校验失败
   */
  bool TimestampCheck(const drogon::HttpRequestPtr& req, std::string& msg,
                      std::string& prompt);
};
}  // namespace ptp::api::v1

#endif