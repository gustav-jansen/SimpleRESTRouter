#include "SimpleRESTManager.hpp"

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "SimpleHTTPParser.hpp"

SimpleRESTManager::~SimpleRESTManager() {
  delete listener;
}

SimpleRESTManager::SimpleRESTManager() {
  listener = new SocketListener(DEFAULT_PORT);
  message_loop();
}

SimpleRESTManager::SimpleRESTManager(std::string ip_address, int port) {
  listener = new SocketListener(ip_address, port);
  message_loop();
}

void SimpleRESTManager::message_loop(void) {
  Message * msg;
  SimpleHTTPParser parser;
  std::string command;
  for ( ; ; ) {
    msg = listener->get_next_message();
    command = parser.get_request_target(msg);

    printf("Command: %s\n", command.c_str());
    delete msg;
  }
}
