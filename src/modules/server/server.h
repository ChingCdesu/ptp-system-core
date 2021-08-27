#ifndef PTP__SERVER_H
#define PTP__SERVER_H

#include <drogon/drogon.h>

#include <thread>

#include "common/enums/returns.h"
#include "common/macros/singleton.h"
#include "common/module.h"

namespace ptp {
namespace module {
class Server : public ptp::common::Module {
  PATTERN_SINGLETON_DECLARE(Server);

 private:
  std::thread thread_;
 public:
  RC Start() override;
  RC Stop() override;
};
}  // namespace module
}  // namespace ptp

#define g_serverImpl (*ptp::module::Server::Instance())

#endif