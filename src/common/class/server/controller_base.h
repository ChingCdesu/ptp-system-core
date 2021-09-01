/**
 * @file controller_base.h
 * @author ChingCdesu (chingc.ccmail@gmail.com)
 * @brief 路由控制基类
 * @version 0.1
 * @date 2021-08-31
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__CONTROLLER_BASE_H
#define PTP__CONTROLLER_BASE_H

#include <drogon/HttpController.h>
#include <drogon/orm/Criteria.h>
#include <drogon/orm/Mapper.h>

#include "common/function/condition.h"
#include "common/function/json.h"
#include "common/function/string.h"
#include "common/function/url.h"
#include "modules/logger/logger_impl.h"
#include "response.h"

using namespace drogon;

namespace ptp::api::v1 {
template <class Modal, class MetaModal>
class base {
 protected:
  using Mp = drogon::orm::Mapper<Modal>;
  using MetaMp = drogon::orm::Mapper<MetaModal>;
  using Criteria = drogon::orm::Criteria;
  using CompareOperator = drogon::orm::CompareOperator;

 public:
  virtual void Create(const HttpRequestPtr& req,
                      std::function<void(const HttpResponsePtr&)>&& callback) {
    try {
      Json::Value json(Json::Value::nullRef);
      std::string json_parse_err;
      auto success =
          ptp::common::json_parse(req->bodyData(), json, json_parse_err);
      if (!success) {
        callback(response::json_error_res(json_parse_err));
      }
      Mp mp = drogon::app().getDbClient();
      std::string err;
      if (!Modal::validateJsonForCreation(json, err)) {
        callback(response::req_data_validation_failed_res(err));
        return;
      }
      Modal obj(json);
      //   obj.setCreatedAt(trantor::Date::now());
      mp.insert(obj);
      auto jObj = obj.toJson();
      callback(response::success_res_with_data(jObj));
    } catch (const Json::Exception& ex) {
      PTP_ERROR("Json Parse Error: {}", ex.what());
      callback(response::json_error_res(ex.what()));
    } catch (const drogon::orm::SqlError& ex) {
      PTP_ERROR("SqlError: {}\n\tquery: {}\n\tstate: {}", ex.what(), ex.query(),
                ex.sqlState());
      callback(response::db_failed_res(ex.what()));
    } catch (const drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("Unknown Database Error: {}", ex.base().what());
      callback(response::db_failed_res(ex.base().what()));
    } catch (const std::exception& ex) {
      PTP_ERROR("Unknown Runtime Error: {}", ex.what());
      callback(response::unknown_failed(ex.what()));
    }
  }

  virtual void Update(const HttpRequestPtr& req,
                      std::function<void(const HttpResponsePtr&)>&& callback,
                      int id) {
    if (id == 0) {
      PTP_ERROR("id参数无法解析");
      callback(response::invalid_argument_res(Modal::tableName + "_id", "int"));
      return;
    }
    try {
      Mp mp = drogon::app().getDbClient();
      Json::Value json(Json::Value::nullRef);
      std::string json_parse_err;
      auto success =
          ptp::common::json_parse(req->bodyData(), json, json_parse_err);
      if (!success) {
        callback(response::json_error_res(json_parse_err));
      }
      auto modal = mp.findByPrimaryKey(id);
      modal.updateByJson(json);
      modal.setId(id);
      mp.update(modal);
      callback(response::success_res_with_data(modal.toJson()));
    } catch (const drogon::orm::UnexpectedRows& ex) {
      callback(response::data_not_found_res());
    } catch (const drogon::orm::SqlError& ex) {
      PTP_ERROR("SqlError: {}\n\tquery: {}\n\tstate: {}", ex.what(), ex.query(),
                ex.sqlState());
      callback(response::db_failed_res(ex.what()));
    } catch (const drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("Unknown Database Error: {}", ex.base().what());
      callback(response::db_failed_res(ex.base().what()));
    } catch (const std::exception& ex) {
      PTP_ERROR("Unknown Runtime Error: {}", ex.what());
      callback(response::unknown_failed(ex.what()));
    }
  }

  virtual void Remove(const HttpRequestPtr& req,
                      std::function<void(const HttpResponsePtr&)>&& callback,
                      int id) {
    if (id == 0) {
      PTP_ERROR("id参数无法解析");
      callback(response::invalid_argument_res(Modal::tableName + "_id", "int"));
      return;
    }
    try {
      Mp mp = drogon::app().getDbClient();
      auto success = mp.deleteByPrimaryKey(id);
      MetaMp metaMp = drogon::app().getDbClient();
      metaMp.deleteBy(
          Criteria(MetaModal::Cols::_relative_id, CompareOperator::EQ, id));
      if (success)
        callback(response::success_res());
      else
        callback(response::data_not_found_res());
    } catch (const drogon::orm::UnexpectedRows& ex) {
      callback(response::data_not_found_res());
    } catch (const drogon::orm::SqlError& ex) {
      PTP_ERROR("SqlError: {}\n\tquery: {}\n\tstate: {}", ex.what(), ex.query(),
                ex.sqlState());
      callback(response::db_failed_res(ex.what()));
    } catch (const drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("Unknown Database Error: {}", ex.base().what());
      callback(response::db_failed_res(ex.base().what()));
    } catch (const std::exception& ex) {
      PTP_ERROR("Unknown Runtime Error: {}", ex.what());
      callback(response::unknown_failed(ex.what()));
    }
  }

  virtual void Read(const HttpRequestPtr& req,
                    std::function<void(const HttpResponsePtr&)>&& callback,
                    int id) {
    if (id == 0) {
      PTP_ERROR("id参数无法解析");
      callback(response::invalid_argument_res(Modal::tableName + "_id", "int"));
      return;
    }
    try {
      Mp mp = drogon::app().getDbClient();
      auto json = mp.findByPrimaryKey(id).toJson();

      MetaMp metaMp = drogon::app().getDbClient();
      auto metadata = metaMp.findBy(
          Criteria(MetaModal::Cols::_relative_id, CompareOperator::EQ, id) &&
          Criteria(MetaModal::Cols::_visible, CompareOperator::EQ, 1));
      json["meta_data"] = Json::objectValue;
      for (const auto& meta : metadata) {
        const auto name = meta.getValueOfMetaName();
        json["meta_data"][name] = meta.getValueOfMetaValue();
      }
      ptp::common::jsonDecodeInlineString(json);
      callback(response::success_res_with_data(json));
    } catch (const drogon::orm::UnexpectedRows& ex) {
      callback(response::data_not_found_res());
    } catch (const drogon::orm::SqlError& ex) {
      PTP_ERROR("SqlError: {}\n\tquery: {}\n\tstate: {}", ex.what(), ex.query(),
                ex.sqlState());
      callback(response::db_failed_res(ex.what()));
    } catch (const drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("Unknown Database Error: {}", ex.base().what());
      callback(response::db_failed_res(ex.base().what()));
    } catch (const std::exception& ex) {
      PTP_ERROR("Unknown Runtime Error: {}", ex.what());
      callback(response::unknown_failed(ex.what()));
    }
  }

  virtual void List(const HttpRequestPtr& req,
                    std::function<void(const HttpResponsePtr&)>&& callback) {
    int per_page = 10, page = 1;
    Criteria condition;
    auto queries = ptp::common::url_query_parse(req->getQuery());
    if (queries.find("per_page") != queries.end()) {
      per_page = ptp::common::str2uint(queries.at("per_page"), 10);
    } else {
      PTP_DEBUG("未找到\"{}\"参数，设置为默认值: {}", "per_page", 10);
    }
    if (queries.find("page") != queries.end()) {
      page = ptp::common::str2uint(queries.at("page"), 1);
    } else {
      PTP_DEBUG("未找到\"{}\"参数，设置为默认值: {}", "page", 1);
    }
    // if (queries.find("keywords") != queries.end()) {
    //   if (search_fields_.empty()) {
    //     for (int i = 0; i < Modal::getColumnNumber(); ++i) {
    //       search_fields_.push_back(Modal::getColumnName(i));
    //     }
    //   }
    //   auto keywords = ptp::common::str_split(queries.at("keywords"), " ");
    //   for (const auto& keyword : keywords)
    //     for (const auto& field : search_fields_)
    //       ptp::common::ConditionOr(condition,
    //                                Criteria(field, CompareOperator::Like,
    //                                         fmt::format("%{}%", keyword)));
    // }
    Mp mp = drogon::app().getDbClient();
    auto count = mp.count(condition);
    mp.limit(per_page);
    mp.offset(per_page * (page - 1));
    auto list = mp.findBy(condition);
    Json::Value data;
    data.resize(0);
    for (const auto& item : list) {
      auto json = item.toJson();
      MetaMp metaMp = drogon::app().getDbClient();
      auto metadata = metaMp.findBy(
          Criteria(MetaModal::Cols::_visible, CompareOperator::EQ, 1));
      json["meta_data"] = Json::objectValue;
      for (const auto& meta : metadata) {
        const auto name = meta.getValueOfMetaName();
        json["meta_data"][name] = meta.getValueOfMetaValue();
      }
      ptp::common::jsonDecodeInlineString(json);
      data.append(json);
    }
    auto response = response::success_res_with_data(data);
    response->addHeader("X-Total", std::to_string(count));
    response->addHeader("X-TotalPage", std::to_string(count / per_page));
    callback(response);
  }

  virtual void SetMeta(const HttpRequestPtr& req,
                       std::function<void(const HttpResponsePtr&)>&& callback,
                       const int& id, const std::string& meta_name) {
    try {
      MetaMp metaMp = drogon::app().getDbClient();
      auto metas = metaMp.findBy(
          Criteria(MetaModal::Cols::_relative_id, CompareOperator::EQ, id) &&
          Criteria(MetaModal::Cols::_meta_name, CompareOperator::EQ,
                   meta_name));
      MetaModal m;
      if (metas.size() == 0) {
        m.setRelativeId(id);
        m.setMetaName(meta_name);
        m.setMetaValue(req->bodyData());
        metaMp.insert(m);
      } else {
        m = metas[0];
        m.setMetaValue(req->bodyData());
        metaMp.update(m);
      }
      callback(response::success_res_with_data(m.toJson()));
    } catch (const drogon::orm::SqlError& ex) {
      PTP_ERROR("SqlError: {}\n\tquery: {}\n\tstate: {}", ex.what(), ex.query(),
                ex.sqlState());
      callback(response::db_failed_res(ex.what()));
    } catch (const drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("Unknown Database Error: {}", ex.base().what());
      callback(response::db_failed_res(ex.base().what()));
    } catch (const std::exception& ex) {
      PTP_ERROR("Unknown Runtime Error: {}", ex.what());
      callback(response::unknown_failed(ex.what()));
    }
  }

  virtual void RemoveMeta(
      const HttpRequestPtr& req,
      std::function<void(const HttpResponsePtr&)>&& callback, const int& id,
      const std::string& meta_name) {
    try {
      MetaMp metaMp = drogon::app().getDbClient();
      auto success = metaMp.deleteBy(
          Criteria(MetaModal::Cols::_relative_id, CompareOperator::EQ, id) &&
          Criteria(MetaModal::Cols::_meta_name, CompareOperator::EQ,
                   meta_name));
      if (success)
        callback(response::success_res());
      else
        callback(response::data_not_found_res());
    } catch (const drogon::orm::SqlError& ex) {
      PTP_ERROR("SqlError: {}\n\tquery: {}\n\tstate: {}", ex.what(), ex.query(),
                ex.sqlState());
      callback(response::db_failed_res(ex.what()));
    } catch (const drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("Unknown Database Error: {}", ex.base().what());
      callback(response::db_failed_res(ex.base().what()));
    } catch (const std::exception& ex) {
      PTP_ERROR("Unknown Runtime Error: {}", ex.what());
      callback(response::unknown_failed(ex.what()));
    }
  }

  virtual void GetMeta(const HttpRequestPtr& req,
                       std::function<void(const HttpResponsePtr&)>&& callback,
                       const int& id, const std::string& meta_name) {
    try {
      MetaMp metaMp = drogon::app().getDbClient();
      auto meta = metaMp.findOne(
          Criteria(MetaModal::Cols::_relative_id, CompareOperator::EQ, id) &&
          Criteria(MetaModal::Cols::_meta_name, CompareOperator::EQ,
                   meta_name));
      auto jMeta = meta.toJson();
      ptp::common::jsonDecodeInlineString(jMeta);
      callback(response::success_res_with_data(jMeta));
    } catch (const drogon::orm::SqlError& ex) {
      PTP_ERROR("SqlError: {}\n\tquery: {}\n\tstate: {}", ex.what(), ex.query(),
                ex.sqlState());
      callback(response::db_failed_res(ex.what()));
    } catch (const drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("Unknown Database Error: {}", ex.base().what());
      callback(response::db_failed_res(ex.base().what()));
    } catch (const std::exception& ex) {
      PTP_ERROR("Unknown Runtime Error: {}", ex.what());
      callback(response::unknown_failed(ex.what()));
    }
  }

  virtual void ListMeta(const HttpRequestPtr& req,
                        std::function<void(const HttpResponsePtr&)>&& callback,
                        const int& id) {
    try {
      MetaMp metaMp = drogon::app().getDbClient();
      auto metas = metaMp.findBy(
          Criteria(MetaModal::Cols::_relative_id, CompareOperator::EQ, id));
      Json::Value jMeta;
      jMeta.resize(0);
      for (const auto& meta : metas) jMeta.append(meta.toJson());
      ptp::common::jsonDecodeInlineString(jMeta);
      callback(response::success_res_with_data(jMeta));
    } catch (const drogon::orm::SqlError& ex) {
      PTP_ERROR("SqlError: {}\n\tquery: {}\n\tstate: {}", ex.what(), ex.query(),
                ex.sqlState());
      callback(response::db_failed_res(ex.what()));
    } catch (const drogon::orm::DrogonDbException& ex) {
      PTP_ERROR("Unknown Database Error: {}", ex.base().what());
      callback(response::db_failed_res(ex.base().what()));
    } catch (const std::exception& ex) {
      PTP_ERROR("Unknown Runtime Error: {}", ex.what());
      callback(response::unknown_failed(ex.what()));
    }
  }
};
}  // namespace ptp::api::v1

#endif  // PTP_CONTROLLER_BASE_H
