/**
 *
 *  PtpTemplate.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#ifdef __cpp_impl_coroutine
#include <drogon/orm/CoroMapper.h>
#endif
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

using namespace drogon::orm;
namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace ptp_system 
{

class PtpTemplate
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _course_id;
        static const std::string _version;
        static const std::string _file;
        static const std::string _fields;
        static const std::string _type;
    };

    const static int primaryKeyNumber;
    const static std::string tableName;
    const static bool hasPrimaryKey;
    const static std::string primaryKeyName;
    using PrimaryKeyType = int32_t;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names, 
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all 
     * columns by an asterisk), please set the offset to -1.
     */
    explicit PtpTemplate(const Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit PtpTemplate(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    PtpTemplate(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    PtpTemplate() = default;
    
    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson, 
                          std::string &err, 
                          bool isForCreation);

    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int32_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getId() const noexcept;

    ///Set the value of the column id
    void setId(const int32_t &pId) noexcept;


    /**  For column course_id  */
    ///Get the value of the column course_id, returns the default value if the column is null
    const int32_t &getValueOfCourseId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getCourseId() const noexcept;

    ///Set the value of the column course_id
    void setCourseId(const int32_t &pCourseId) noexcept;


    /**  For column version  */
    ///Get the value of the column version, returns the default value if the column is null
    const int32_t &getValueOfVersion() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getVersion() const noexcept;

    ///Set the value of the column version
    void setVersion(const int32_t &pVersion) noexcept;


    /**  For column file  */
    ///Get the value of the column file, returns the default value if the column is null
    const std::string &getValueOfFile() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFile() const noexcept;

    ///Set the value of the column file
    void setFile(const std::string &pFile) noexcept;
    void setFile(std::string &&pFile) noexcept;


    /**  For column fields  */
    ///Get the value of the column fields, returns the default value if the column is null
    const std::string &getValueOfFields() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFields() const noexcept;

    ///Set the value of the column fields
    void setFields(const std::string &pFields) noexcept;
    void setFields(std::string &&pFields) noexcept;


    /**  For column type  */
    ///Get the value of the column type, returns the default value if the column is null
    const std::string &getValueOfType() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getType() const noexcept;

    ///Set the value of the column type
    void setType(const std::string &pType) noexcept;
    void setType(std::string &&pType) noexcept;



    static size_t getColumnNumber() noexcept {  return 6;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend Mapper<PtpTemplate>;
#ifdef __cpp_impl_coroutine
    friend CoroMapper<PtpTemplate>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> id_;
    std::shared_ptr<int32_t> courseId_;
    std::shared_ptr<int32_t> version_;
    std::shared_ptr<std::string> file_;
    std::shared_ptr<std::string> fields_;
    std::shared_ptr<std::string> type_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[6]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where id = ?";
        return sql;                   
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where id = ?";
        return sql;                   
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
            sql += "id,";
            ++parametersCount;
        if(dirtyFlag_[1])
        {
            sql += "course_id,";
            ++parametersCount;
        }
        sql += "version,";
        ++parametersCount;
        if(!dirtyFlag_[2])
        {
            needSelection=true;
        }
        if(dirtyFlag_[3])
        {
            sql += "file,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "fields,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "type,";
            ++parametersCount;
        }
        needSelection=true;
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";
        
        sql +="default,";
        if(dirtyFlag_[1])
        {
            sql.append("?,");

        } 
        if(dirtyFlag_[2])
        {
            sql.append("?,");

        } 
        else
        {
            sql +="default,";
        }
        if(dirtyFlag_[3])
        {
            sql.append("?,");

        } 
        if(dirtyFlag_[4])
        {
            sql.append("?,");

        } 
        if(dirtyFlag_[5])
        {
            sql.append("?,");

        } 
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        sql.append(1, ')');
        LOG_TRACE << sql;
        return sql;   
    }
};
} // namespace ptp_system
} // namespace drogon_model
