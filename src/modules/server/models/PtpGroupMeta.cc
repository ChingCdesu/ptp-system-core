/**
 *
 *  PtpGroupMeta.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "PtpGroupMeta.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::ptp_system;

const std::string PtpGroupMeta::Cols::_id = "id";
const std::string PtpGroupMeta::Cols::_relative_id = "relative_id";
const std::string PtpGroupMeta::Cols::_meta_name = "meta_name";
const std::string PtpGroupMeta::Cols::_meta_value = "meta_value";
const std::string PtpGroupMeta::primaryKeyName = "id";
const bool PtpGroupMeta::hasPrimaryKey = true;
const std::string PtpGroupMeta::tableName = "ptp_group_meta";

const std::vector<typename PtpGroupMeta::MetaData> PtpGroupMeta::metaData_={
{"id","int32_t","int",4,1,1,1},
{"relative_id","int32_t","int",4,0,0,1},
{"meta_name","std::string","varchar(255)",255,0,0,1},
{"meta_value","std::string","json",0,0,0,1}
};
const std::string &PtpGroupMeta::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
PtpGroupMeta::PtpGroupMeta(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["relative_id"].isNull())
        {
            relativeId_=std::make_shared<int32_t>(r["relative_id"].as<int32_t>());
        }
        if(!r["meta_name"].isNull())
        {
            metaName_=std::make_shared<std::string>(r["meta_name"].as<std::string>());
        }
        if(!r["meta_value"].isNull())
        {
            metaValue_=std::make_shared<std::string>(r["meta_value"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 4 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            relativeId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            metaName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            metaValue_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

PtpGroupMeta::PtpGroupMeta(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            relativeId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            metaName_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());

        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            metaValue_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());

        }
    }
}

PtpGroupMeta::PtpGroupMeta(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("relative_id"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["relative_id"].isNull())
        {
            relativeId_=std::make_shared<int32_t>((int32_t)pJson["relative_id"].asInt64());
        }
    }
    if(pJson.isMember("meta_name"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["meta_name"].isNull())
        {
            metaName_=std::make_shared<std::string>(pJson["meta_name"].asString());
        }
    }
    if(pJson.isMember("meta_value"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["meta_value"].isNull())
        {
            metaValue_=std::make_shared<std::string>(pJson["meta_value"].asString());
        }
    }
}

void PtpGroupMeta::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            relativeId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            metaName_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            metaValue_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
}
                                                                    
void PtpGroupMeta::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("relative_id"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["relative_id"].isNull())
        {
            relativeId_=std::make_shared<int32_t>((int32_t)pJson["relative_id"].asInt64());
        }
    }
    if(pJson.isMember("meta_name"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["meta_name"].isNull())
        {
            metaName_=std::make_shared<std::string>(pJson["meta_name"].asString());
        }
    }
    if(pJson.isMember("meta_value"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["meta_value"].isNull())
        {
            metaValue_=std::make_shared<std::string>(pJson["meta_value"].asString());
        }
    }
}

const int32_t &PtpGroupMeta::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &PtpGroupMeta::getId() const noexcept
{
    return id_;
}
void PtpGroupMeta::setId(const int32_t &pId) noexcept
{
    id_ = std::make_shared<int32_t>(pId);
    dirtyFlag_[0] = true;
}



const typename PtpGroupMeta::PrimaryKeyType & PtpGroupMeta::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const int32_t &PtpGroupMeta::getValueOfRelativeId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(relativeId_)
        return *relativeId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &PtpGroupMeta::getRelativeId() const noexcept
{
    return relativeId_;
}
void PtpGroupMeta::setRelativeId(const int32_t &pRelativeId) noexcept
{
    relativeId_ = std::make_shared<int32_t>(pRelativeId);
    dirtyFlag_[1] = true;
}




const std::string &PtpGroupMeta::getValueOfMetaName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(metaName_)
        return *metaName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &PtpGroupMeta::getMetaName() const noexcept
{
    return metaName_;
}
void PtpGroupMeta::setMetaName(const std::string &pMetaName) noexcept
{
    metaName_ = std::make_shared<std::string>(pMetaName);
    dirtyFlag_[2] = true;
}
void PtpGroupMeta::setMetaName(std::string &&pMetaName) noexcept
{
    metaName_ = std::make_shared<std::string>(std::move(pMetaName));
    dirtyFlag_[2] = true;
}




const std::string &PtpGroupMeta::getValueOfMetaValue() const noexcept
{
    const static std::string defaultValue = std::string();
    if(metaValue_)
        return *metaValue_;
    return defaultValue;
}
const std::shared_ptr<std::string> &PtpGroupMeta::getMetaValue() const noexcept
{
    return metaValue_;
}
void PtpGroupMeta::setMetaValue(const std::string &pMetaValue) noexcept
{
    metaValue_ = std::make_shared<std::string>(pMetaValue);
    dirtyFlag_[3] = true;
}
void PtpGroupMeta::setMetaValue(std::string &&pMetaValue) noexcept
{
    metaValue_ = std::make_shared<std::string>(std::move(pMetaValue));
    dirtyFlag_[3] = true;
}




void PtpGroupMeta::updateId(const uint64_t id)
{
    id_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &PtpGroupMeta::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "relative_id",
        "meta_name",
        "meta_value"
    };
    return inCols;
}

void PtpGroupMeta::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getRelativeId())
        {
            binder << getValueOfRelativeId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getMetaName())
        {
            binder << getValueOfMetaName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getMetaValue())
        {
            binder << getValueOfMetaValue();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> PtpGroupMeta::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    return ret;
}

void PtpGroupMeta::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getRelativeId())
        {
            binder << getValueOfRelativeId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getMetaName())
        {
            binder << getValueOfMetaName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getMetaValue())
        {
            binder << getValueOfMetaValue();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value PtpGroupMeta::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getRelativeId())
    {
        ret["relative_id"]=getValueOfRelativeId();
    }
    else
    {
        ret["relative_id"]=Json::Value();
    }
    if(getMetaName())
    {
        ret["meta_name"]=getValueOfMetaName();
    }
    else
    {
        ret["meta_name"]=Json::Value();
    }
    if(getMetaValue())
    {
        ret["meta_value"]=getValueOfMetaValue();
    }
    else
    {
        ret["meta_value"]=Json::Value();
    }
    return ret;
}

Json::Value PtpGroupMeta::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 4)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getRelativeId())
            {
                ret[pMasqueradingVector[1]]=getValueOfRelativeId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getMetaName())
            {
                ret[pMasqueradingVector[2]]=getValueOfMetaName();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getMetaValue())
            {
                ret[pMasqueradingVector[3]]=getValueOfMetaValue();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getRelativeId())
    {
        ret["relative_id"]=getValueOfRelativeId();
    }
    else
    {
        ret["relative_id"]=Json::Value();
    }
    if(getMetaName())
    {
        ret["meta_name"]=getValueOfMetaName();
    }
    else
    {
        ret["meta_name"]=Json::Value();
    }
    if(getMetaValue())
    {
        ret["meta_value"]=getValueOfMetaValue();
    }
    else
    {
        ret["meta_value"]=Json::Value();
    }
    return ret;
}

bool PtpGroupMeta::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("relative_id"))
    {
        if(!validJsonOfField(1, "relative_id", pJson["relative_id"], err, true))
            return false;
    }
    else
    {
        err="The relative_id column cannot be null";
        return false;
    }
    if(pJson.isMember("meta_name"))
    {
        if(!validJsonOfField(2, "meta_name", pJson["meta_name"], err, true))
            return false;
    }
    else
    {
        err="The meta_name column cannot be null";
        return false;
    }
    if(pJson.isMember("meta_value"))
    {
        if(!validJsonOfField(3, "meta_value", pJson["meta_value"], err, true))
            return false;
    }
    else
    {
        err="The meta_value column cannot be null";
        return false;
    }
    return true;
}
bool PtpGroupMeta::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                      const std::vector<std::string> &pMasqueradingVector,
                                                      std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[3] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e) 
    {
      err = e.what();
      return false;
    }
    return true;
}
bool PtpGroupMeta::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("relative_id"))
    {
        if(!validJsonOfField(1, "relative_id", pJson["relative_id"], err, false))
            return false;
    }
    if(pJson.isMember("meta_name"))
    {
        if(!validJsonOfField(2, "meta_name", pJson["meta_name"], err, false))
            return false;
    }
    if(pJson.isMember("meta_value"))
    {
        if(!validJsonOfField(3, "meta_value", pJson["meta_value"], err, false))
            return false;
    }
    return true;
}
bool PtpGroupMeta::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                    const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e) 
    {
      err = e.what();
      return false;
    }
    return true;
}
bool PtpGroupMeta::validJsonOfField(size_t index,
                                    const std::string &fieldName,
                                    const Json::Value &pJson, 
                                    std::string &err, 
                                    bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }        
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 255)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 255)";
                return false;               
            }

            break;
        case 3:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            break;
     
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}
