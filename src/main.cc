#include <uv.h>

#include <chrono>
#include <iostream>
#include <thread>
#include <mysql.h>

#include "modules/logger/logger_impl.h"

using namespace std::chrono_literals;

void StartAllModules() {
  g_LoggerImpl.Start();
  PTP_INFO(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  PTP_INFO("Starting modules...");
  PTP_INFO("Finished starting up");
}

void StopAllModules() {
  PTP_INFO(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  PTP_INFO("Stoping modules...");
  PTP_INFO("Finished shutdown");
  g_LoggerImpl.Stop();
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

  uv_run(uv_default_loop(), UV_RUN_DEFAULT);

  StopAllModules();

  return 0;
}
