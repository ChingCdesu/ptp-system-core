/**
 * @file main.cc
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 入口文件，包含信号处理和模块启动停止功能
 * @version 0.1
 * @date 2021-08-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <spdlog/stopwatch.h>
#include <uv.h>

#include <chrono>
#include <thread>

#include "common/class/interval.h"
#include "modules/docx/service.h"
#include "modules/logger/logger_impl.h"
#include "modules/server/server.h"
#include "modules/xlsx/service.h"

void StartAllModules() {
  g_Logger.Start();
  PTP_INFO(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  PTP_INFO("Starting modules...");
  spdlog::stopwatch sw;
  g_docxService.Start();
  g_xlsxService.Start();
  g_Server.Start();
  PTP_INFO("Finished starting up, elapsed {:.6}s", sw);
}

void StopAllModules() {
  PTP_INFO(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  PTP_INFO("Stoping modules...");
  spdlog::stopwatch sw;
  g_Server.Stop();
  g_xlsxService.Stop();
  g_docxService.Stop();
  PTP_INFO("Finished shutdown, elapsed {:.6}s", sw);
  g_Logger.Stop();
}

void SignalCallback(uv_signal_t* handle, int sig) {
  StopAllModules();
  uv_close((uv_handle_t*)handle, NULL);
}

int main() {
  uv_signal_t sig;
  uv_loop_init(uv_default_loop());

  uv_signal_init(uv_default_loop(), &sig);
  uv_signal_start(&sig, SignalCallback, SIGINT);

  StartAllModules();

  using Node = ptp::common::Interval<int>::Node;

  ptp::common::Interval<int> a(Node(12, ptp::common::CLOSE),
                               Node(34, ptp::common::CLOSE));
  ptp::common::Interval<int> b(Node(32, ptp::common::OPEN),
                               Node(56, ptp::common::CLOSE));

  auto result = a.Intersection(b);
  PTP_INFO("{}", result.ToString());

  uv_run(uv_default_loop(), UV_RUN_DEFAULT);

  return 0;
}
