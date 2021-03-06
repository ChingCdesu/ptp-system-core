/**
 *
 *  PtpCourse.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "PtpCourse.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::ptp_system;

const std::string PtpCourse::Cols::_id = "id";
const std::string PtpCourse::Cols::_course_name = "course_name";
const std::string PtpCourse::Cols::_teacher_id = "teacher_id";
const std::string PtpCourse::Cols::_start_time = "start_time";
const std::string PtpCourse::Cols::_end_time = "end_time";
const std::string PtpCourse::Cols::_student_group = "student_group";
const std::string PtpCourse::primaryKeyName = "id";
const bool PtpCourse::hasPrimaryKey = true;
const std::string PtpCourse::tableName = "ptp_course";

const std::vector<typename PtpCourse::MetaData> PtpCourse::metaData_={
{"id","int32_t","int",4,1,1,1},
{"course_name","std::string","varchar(255)",255,0,0,1},
{"teacher_id","int32_t","int",4,0,0,1},
{"start_time","::trantor::Date","datetime",0,0,0,1},
{"end_time","::trantor::Date","datetime",0,0,0,1},
{"student_group","std::string","json",0,0,0,1}
};
const std::string &PtpCourse::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
PtpCourse::PtpCourse(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["course_name"].isNull())
        {
            courseName_=std::make_shared<std::string>(r["course_name"].as<std::string>());
        }
        if(!r["teacher_id"].isNull())
        {
            teacherId_=std::make_shared<int32_t>(r["teacher_id"].as<int32_t>());
        }
        if(!r["start_time"].isNull())
        {
            auto timeStr = r["start_time"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                startTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
        if(!r["end_time"].isNull())
        {
            auto timeStr = r["end_time"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                endTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
        if(!r["student_group"].isNull())
        {
            studentGroup_=std::make_shared<std::string>(r["student_group"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 6 > r.size())
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
            courseName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            teacherId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            auto timeStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                startTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            auto timeStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                endTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            studentGroup_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

PtpCourse::PtpCourse(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
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
            courseName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());

        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            teacherId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[3]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                startTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[4]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                endTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            studentGroup_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());

        }
    }
}

PtpCourse::PtpCourse(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("course_name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["course_name"].isNull())
        {
            courseName_=std::make_shared<std::string>(pJson["course_name"].asString());
        }
    }
    if(pJson.isMember("teacher_id"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["teacher_id"].isNull())
        {
            teacherId_=std::make_shared<int32_t>((int32_t)pJson["teacher_id"].asInt64());
        }
    }
    if(pJson.isMember("start_time"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["start_time"].isNull())
        {
            auto timeStr = pJson["start_time"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                startTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    if(pJson.isMember("end_time"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["end_time"].isNull())
        {
            auto timeStr = pJson["end_time"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                endTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    if(pJson.isMember("student_group"))
    {
        dirtyFlag_[5]=true;
        if(!pJson["student_group"].isNull())
        {
            studentGroup_=std::make_shared<std::string>(pJson["student_group"].asString());
        }
    }
}

void PtpCourse::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
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
            courseName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            teacherId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[3]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                startTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[4]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                endTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            studentGroup_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
}
                                                                    
void PtpCourse::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("course_name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["course_name"].isNull())
        {
            courseName_=std::make_shared<std::string>(pJson["course_name"].asString());
        }
    }
    if(pJson.isMember("teacher_id"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["teacher_id"].isNull())
        {
            teacherId_=std::make_shared<int32_t>((int32_t)pJson["teacher_id"].asInt64());
        }
    }
    if(pJson.isMember("start_time"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["start_time"].isNull())
        {
            auto timeStr = pJson["start_time"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                startTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    if(pJson.isMember("end_time"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["end_time"].isNull())
        {
            auto timeStr = pJson["end_time"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                endTime_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    if(pJson.isMember("student_group"))
    {
        dirtyFlag_[5] = true;
        if(!pJson["student_group"].isNull())
        {
            studentGroup_=std::make_shared<std::string>(pJson["student_group"].asString());
        }
    }
}

const int32_t &PtpCourse::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &PtpCourse::getId() const noexcept
{
    return id_;
}
void PtpCourse::setId(const int32_t &pId) noexcept
{
    id_ = std::make_shared<int32_t>(pId);
    dirtyFlag_[0] = true;
}



const typename PtpCourse::PrimaryKeyType & PtpCourse::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &PtpCourse::getValueOfCourseName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(courseName_)
        return *courseName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &PtpCourse::getCourseName() const noexcept
{
    return courseName_;
}
void PtpCourse::setCourseName(const std::string &pCourseName) noexcept
{
    courseName_ = std::make_shared<std::string>(pCourseName);
    dirtyFlag_[1] = true;
}
void PtpCourse::setCourseName(std::string &&pCourseName) noexcept
{
    courseName_ = std::make_shared<std::string>(std::move(pCourseName));
    dirtyFlag_[1] = true;
}




const int32_t &PtpCourse::getValueOfTeacherId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(teacherId_)
        return *teacherId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &PtpCourse::getTeacherId() const noexcept
{
    return teacherId_;
}
void PtpCourse::setTeacherId(const int32_t &pTeacherId) noexcept
{
    teacherId_ = std::make_shared<int32_t>(pTeacherId);
    dirtyFlag_[2] = true;
}




const ::trantor::Date &PtpCourse::getValueOfStartTime() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(startTime_)
        return *startTime_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &PtpCourse::getStartTime() const noexcept
{
    return startTime_;
}
void PtpCourse::setStartTime(const ::trantor::Date &pStartTime) noexcept
{
    startTime_ = std::make_shared<::trantor::Date>(pStartTime);
    dirtyFlag_[3] = true;
}




const ::trantor::Date &PtpCourse::getValueOfEndTime() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(endTime_)
        return *endTime_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &PtpCourse::getEndTime() const noexcept
{
    return endTime_;
}
void PtpCourse::setEndTime(const ::trantor::Date &pEndTime) noexcept
{
    endTime_ = std::make_shared<::trantor::Date>(pEndTime);
    dirtyFlag_[4] = true;
}




const std::string &PtpCourse::getValueOfStudentGroup() const noexcept
{
    const static std::string defaultValue = std::string();
    if(studentGroup_)
        return *studentGroup_;
    return defaultValue;
}
const std::shared_ptr<std::string> &PtpCourse::getStudentGroup() const noexcept
{
    return studentGroup_;
}
void PtpCourse::setStudentGroup(const std::string &pStudentGroup) noexcept
{
    studentGroup_ = std::make_shared<std::string>(pStudentGroup);
    dirtyFlag_[5] = true;
}
void PtpCourse::setStudentGroup(std::string &&pStudentGroup) noexcept
{
    studentGroup_ = std::make_shared<std::string>(std::move(pStudentGroup));
    dirtyFlag_[5] = true;
}




void PtpCourse::updateId(const uint64_t id)
{
    id_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &PtpCourse::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "course_name",
        "teacher_id",
        "start_time",
        "end_time",
        "student_group"
    };
    return inCols;
}

void PtpCourse::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getCourseName())
        {
            binder << getValueOfCourseName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getTeacherId())
        {
            binder << getValueOfTeacherId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getStartTime())
        {
            binder << getValueOfStartTime();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getEndTime())
        {
            binder << getValueOfEndTime();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getStudentGroup())
        {
            binder << getValueOfStudentGroup();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> PtpCourse::updateColumns() const
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
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    if(dirtyFlag_[5])
    {
        ret.push_back(getColumnName(5));
    }
    return ret;
}

void PtpCourse::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getCourseName())
        {
            binder << getValueOfCourseName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getTeacherId())
        {
            binder << getValueOfTeacherId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getStartTime())
        {
            binder << getValueOfStartTime();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getEndTime())
        {
            binder << getValueOfEndTime();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getStudentGroup())
        {
            binder << getValueOfStudentGroup();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value PtpCourse::toJson() const
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
    if(getCourseName())
    {
        ret["course_name"]=getValueOfCourseName();
    }
    else
    {
        ret["course_name"]=Json::Value();
    }
    if(getTeacherId())
    {
        ret["teacher_id"]=getValueOfTeacherId();
    }
    else
    {
        ret["teacher_id"]=Json::Value();
    }
    if(getStartTime())
    {
        ret["start_time"]=getStartTime()->toDbStringLocal();
    }
    else
    {
        ret["start_time"]=Json::Value();
    }
    if(getEndTime())
    {
        ret["end_time"]=getEndTime()->toDbStringLocal();
    }
    else
    {
        ret["end_time"]=Json::Value();
    }
    if(getStudentGroup())
    {
        ret["student_group"]=getValueOfStudentGroup();
    }
    else
    {
        ret["student_group"]=Json::Value();
    }
    return ret;
}

Json::Value PtpCourse::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 6)
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
            if(getCourseName())
            {
                ret[pMasqueradingVector[1]]=getValueOfCourseName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getTeacherId())
            {
                ret[pMasqueradingVector[2]]=getValueOfTeacherId();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getStartTime())
            {
                ret[pMasqueradingVector[3]]=getStartTime()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getEndTime())
            {
                ret[pMasqueradingVector[4]]=getEndTime()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getStudentGroup())
            {
                ret[pMasqueradingVector[5]]=getValueOfStudentGroup();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
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
    if(getCourseName())
    {
        ret["course_name"]=getValueOfCourseName();
    }
    else
    {
        ret["course_name"]=Json::Value();
    }
    if(getTeacherId())
    {
        ret["teacher_id"]=getValueOfTeacherId();
    }
    else
    {
        ret["teacher_id"]=Json::Value();
    }
    if(getStartTime())
    {
        ret["start_time"]=getStartTime()->toDbStringLocal();
    }
    else
    {
        ret["start_time"]=Json::Value();
    }
    if(getEndTime())
    {
        ret["end_time"]=getEndTime()->toDbStringLocal();
    }
    else
    {
        ret["end_time"]=Json::Value();
    }
    if(getStudentGroup())
    {
        ret["student_group"]=getValueOfStudentGroup();
    }
    else
    {
        ret["student_group"]=Json::Value();
    }
    return ret;
}

bool PtpCourse::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("course_name"))
    {
        if(!validJsonOfField(1, "course_name", pJson["course_name"], err, true))
            return false;
    }
    else
    {
        err="The course_name column cannot be null";
        return false;
    }
    if(pJson.isMember("teacher_id"))
    {
        if(!validJsonOfField(2, "teacher_id", pJson["teacher_id"], err, true))
            return false;
    }
    else
    {
        err="The teacher_id column cannot be null";
        return false;
    }
    if(pJson.isMember("start_time"))
    {
        if(!validJsonOfField(3, "start_time", pJson["start_time"], err, true))
            return false;
    }
    else
    {
        err="The start_time column cannot be null";
        return false;
    }
    if(pJson.isMember("end_time"))
    {
        if(!validJsonOfField(4, "end_time", pJson["end_time"], err, true))
            return false;
    }
    else
    {
        err="The end_time column cannot be null";
        return false;
    }
    if(pJson.isMember("student_group"))
    {
        if(!validJsonOfField(5, "student_group", pJson["student_group"], err, true))
            return false;
    }
    else
    {
        err="The student_group column cannot be null";
        return false;
    }
    return true;
}
bool PtpCourse::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                   const std::vector<std::string> &pMasqueradingVector,
                                                   std::string &err)
{
    if(pMasqueradingVector.size() != 6)
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
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[4] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[5].empty())
      {
          if(pJson.isMember(pMasqueradingVector[5]))
          {
              if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[5] + " column cannot be null";
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
bool PtpCourse::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
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
    if(pJson.isMember("course_name"))
    {
        if(!validJsonOfField(1, "course_name", pJson["course_name"], err, false))
            return false;
    }
    if(pJson.isMember("teacher_id"))
    {
        if(!validJsonOfField(2, "teacher_id", pJson["teacher_id"], err, false))
            return false;
    }
    if(pJson.isMember("start_time"))
    {
        if(!validJsonOfField(3, "start_time", pJson["start_time"], err, false))
            return false;
    }
    if(pJson.isMember("end_time"))
    {
        if(!validJsonOfField(4, "end_time", pJson["end_time"], err, false))
            return false;
    }
    if(pJson.isMember("student_group"))
    {
        if(!validJsonOfField(5, "student_group", pJson["student_group"], err, false))
            return false;
    }
    return true;
}
bool PtpCourse::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                 const std::vector<std::string> &pMasqueradingVector,
                                                 std::string &err)
{
    if(pMasqueradingVector.size() != 6)
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
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
              return false;
      }
      if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
      {
          if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
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
bool PtpCourse::validJsonOfField(size_t index,
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
        case 2:
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
        case 4:
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
        case 5:
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
