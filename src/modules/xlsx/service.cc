/**
 * @file service.cc
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief Excel文档支持服务
 * @version 0.1
 * @date 2021-08-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "service.h"

namespace ptp {
namespace module {
PATTERN_SINGLETON_IMPLEMENT(XlsxService);

XlsxService::XlsxService() {
  name_ = "xlsx-service";
  version_ = "0.1.0";
}
XlsxService::~XlsxService() {}

RC XlsxService::Start() { return RC::SUCCESS; }

RC XlsxService::Stop() { return RC::SUCCESS; }

void XlsxService::testXlsx(const std::string& filename) {
  OpenXLSX::XLDocument doc;
  doc.create(filename);
  auto wks = doc.workbook().worksheet("Sheet1");

  // Here an address string is used in the .cell member function, but an
  // XLCellReference object can also be used. For example, for the cell at 'A1',
  // XLCellReference{1,1} can be usedas an argument.
  wks.cell("A1").value().set(3.14159);
  wks.cell("B1").value() = 42;
  wks.cell("C1").value() = "  Hello OpenXLSX!  ";
  wks.cell("D1").value() = true;
  wks.cell("E1").value() = wks.cell(OpenXLSX::XLCellReference("C1")).value();

  OpenXLSX::XLCellValue A1 = wks.cell("A1").value();
  OpenXLSX::XLCellValue B1 = wks.cell("B1").value();
  OpenXLSX::XLCellValue C1 = wks.cell("C1").value();
  OpenXLSX::XLCellValue D1 = wks.cell("D1").value();
  OpenXLSX::XLCellValue E1 = wks.cell("E1").value();

  std::cout << "Cell A1: (" << A1.typeAsString() << ") " << A1.get<double>() << std::endl;
  std::cout << "Cell B1: (" << B1.typeAsString() << ") " << B1.get<int64_t>()
       << std::endl;
  std::cout << "Cell C1: (" << C1.typeAsString() << ") " << C1.get<std::string>()
       << std::endl;
  std::cout << "Cell D1: (" << D1.typeAsString() << ") " << D1.get<bool>() << std::endl;
  std::cout << "Cell E1: (" << E1.typeAsString() << ") "
       << E1.get<std::string_view>() << std::endl
       << std::endl;

  doc.save();
}

}  // namespace module
}  // namespace ptp