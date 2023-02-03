/**
 * @file main.cpp
 * @brief ftp main
 * @author shixinzhang@scutech.com
 * @version 1.0
 * @date 2023-01-07
 */
#include "container/Headers.h"
#include "network/Server.h"

#define SERVER_PORT 5010

int main() {
  Server svr(SERVER_PORT, (char *)"127.0.0.1");
  svr.init();
  ACE_Reactor::instance()->register_handler(
      &svr, ACE_Event_Handler::ACCEPT_MASK);  // listen port注册到ACE_Reactor
  ACE_Reactor::instance()
      ->run_reactor_event_loop();  //进入消息循环，有I/O事件回调handle_input
  return 0;
}
