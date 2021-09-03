/**
 * @file authorize.h
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__CONTROLLER_AUTHORIZE_H
#define PTP__CONTROLLER_AUTHORIZE_H

#include <drogon/HttpController.h>

#include "common/class/server/response.h"
#include "common/crypto/hmac.h"
#include "common/crypto/sha256.h"
#include "modules/server/models/PtpUser.h"
#include "modules/server/models/PtpUserMeta.h"

#ifdef BASE_CONTROLLER_PATH
#undef BASE_CONTROLLER_PATH
#endif

#define BASE_CONTROLLER_PATH "/authorize"

namespace ptp::api::v1 {
using User = drogon_model::ptp_system::PtpUser;
using UserMeta = drogon_model::ptp_system::PtpUserMeta;

class AuthorizeController : public drogon::HttpController<AuthorizeController> {
 public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(AuthorizeController::Login, BASE_CONTROLLER_PATH, drogon::Post);
  ADD_METHOD_TO(AuthorizeController::Logout, BASE_CONTROLLER_PATH, drogon::Delete);
  METHOD_LIST_END
 public:
  void Login(const drogon::HttpRequestPtr& req,
             std::function<void(const drogon::HttpResponsePtr&)>&& callback);
  void Logout(const drogon::HttpRequestPtr& req,
              std::function<void(const drogon::HttpResponsePtr&)>&& callback);
};
}  // namespace ptp::api::v1

#endif