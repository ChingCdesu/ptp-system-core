/**
 * @file service.cc
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief Word文档支持服务
 * @version 0.1
 * @date 2021-08-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "service.h"

#include <iostream>

namespace ptp {
namespace module {
PATTERN_SINGLETON_IMPLEMENT(DocxService);

DocxService::DocxService() {
  name_ = "docx-service";
  version_ = "0.1.0";
}
DocxService::~DocxService() {}

RC DocxService::Start() { return RC::SUCCESS; }

RC DocxService::Stop() { return RC::SUCCESS; }

void DocxService::testDocx(const std::string& filename) {
  duckx::Document doc(filename);
  doc.open();
  int para_count = 0;

  for (auto p = doc.paragraphs(); p.has_next(); p.next()) {
    fmt::print("paragraph {}:\n", ++para_count);
    for (auto r = p.runs(); r.has_next(); r.next()) {
      std::cout << r.get_text();
    }
    std::cout << std::endl;
  }

  int table_count = 0;
  for (auto t = doc.tables(); t.has_next(); t.next()) {
    fmt::print("table {}:\n", ++table_count);
    for (auto row = t.rows(); row.has_next(); row.next()) {
      for (auto c = row.cells(); c.has_next(); c.next()) {
        for (auto p = c.paragraphs(); p.has_next(); p.next()) {
          for (auto r = p.runs(); r.has_next(); r.next()) {
            std::cout << r.get_text();
          }
          std::cout << std::endl;
        }
      }
    }
  }
}

}  // namespace module
}  // namespace ptp