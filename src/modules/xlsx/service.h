/**
 * @file service.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief Excel文档支持服务
 * @version 0.1
 * @date 2021-08-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__XLSX_SERVICE_H
#define PTP__XLSX_SERVICE_H

#include <string>
#include <OpenXLSX.hpp>

#include "common/class/module.h"
#include "common/enums/returns.h"
#include "common/macros/singleton.h"
#include "modules/logger/logger_impl.h"

namespace ptp {
namespace module {
class XlsxService : public ptp::common::Module {
  PATTERN_SINGLETON_DECLARE(XlsxService);

 public:
  RC Start() override;
  RC Stop() override;

 public:
  void testXlsx(const std::string& filename);
};

#define g_xlsxService (*ptp::module::XlsxService::Instance())

}  // namespace module
}  // namespace ptp

#endif