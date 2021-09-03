/**
 * @file user.h
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__CONTROLLER_USER_H
#define PTP__CONTROLLER_USER_H

#include <drogon/HttpController.h>

#include "common/class/server/controller_base.h"
#include "modules/server/models/PtpUser.h"
#include "modules/server/models/PtpUserMeta.h"

#ifdef BASE_CONTROLLER_PATH
#undef BASE_CONTROLLER_PATH
#endif

#define BASE_CONTROLLER_PATH "/api/v1/users"
#define AUTHORIZE_FILTER "ptp::api::v1::AuthorizeFilter"

namespace ptp::api::v1 {
using User = drogon_model::ptp_system::PtpUser;
using UserMeta = drogon_model::ptp_system::PtpUserMeta;

class UserController : public base<User, UserMeta>,
                       public drogon::HttpController<UserController> {
 public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(UserController::Create, BASE_CONTROLLER_PATH, Post,
                AUTHORIZE_FILTER);
  ADD_METHOD_TO(UserController::Update, BASE_CONTROLLER_PATH "/{id}", Put,
                AUTHORIZE_FILTER);
  ADD_METHOD_TO(UserController::Read, BASE_CONTROLLER_PATH "/{id}", Get,
                AUTHORIZE_FILTER);
  ADD_METHOD_TO(UserController::Remove, BASE_CONTROLLER_PATH "/{id}", Post,
                AUTHORIZE_FILTER);
  ADD_METHOD_TO(UserController::List, BASE_CONTROLLER_PATH, Get,
                AUTHORIZE_FILTER);

  ADD_METHOD_TO(UserController::SetMeta,
                BASE_CONTROLLER_PATH "/{id}/meta/{meta_id}", Post,
                AUTHORIZE_FILTER);
  ADD_METHOD_TO(UserController::GetMeta,
                BASE_CONTROLLER_PATH "/{id}/meta/{meta_id}", Get,
                AUTHORIZE_FILTER);
  ADD_METHOD_TO(UserController::RemoveMeta,
                BASE_CONTROLLER_PATH "/{id}/meta/{meta_id}", Delete,
                AUTHORIZE_FILTER);
  ADD_METHOD_TO(UserController::ListMeta, BASE_CONTROLLER_PATH "/{id}/meta",
                Get, AUTHORIZE_FILTER);
  METHOD_LIST_END
};

}  // namespace ptp::api::v1

#endif