/**
 * @file service.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief Word文档支持服务
 * @version 0.1
 * @date 2021-08-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__DOCX_SERVICE_H
#define PTP__DOCX_SERVICE_H

#include <string>
#include <duckx.hpp>

#include "common/class/module.h"
#include "common/enums/returns.h"
#include "common/macros/singleton.h"
#include "modules/logger/logger_impl.h"

namespace ptp {
namespace module {
class DocxService : public ptp::common::Module {
  PATTERN_SINGLETON_DECLARE(DocxService);

 public:
  RC Start() override;
  RC Stop() override;

 public:
  void testDocx(const std::string& filename);
};

#define g_docxService (*ptp::module::DocxService::Instance())

}  // namespace module
}  // namespace ptp

#endif