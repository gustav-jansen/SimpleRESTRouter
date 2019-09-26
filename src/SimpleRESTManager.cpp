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
  std::thread loop(&SimpleRESTManager::message_loop, this);
  loop.detach();
}

SimpleRESTManager::SimpleRESTManager(std::string ip_address, int port) {
  listener = new SocketListener(ip_address, port);
  std::thread loop(&SimpleRESTManager::message_loop, this);
  loop.detach();
}

void SimpleRESTManager::message_loop(void) {
  Message * msg;
  SimpleHTTPParser parser;

  while (true ) {
    msg = listener->get_next_message();
    handle_command(parser.get_request_target(msg));
    delete msg;
  }
}

void SimpleRESTManager::handle_command(std::string command) {
  std::map<std::string, SimpleRESTHandler*>::iterator it;

  it = handlers.find(command);
  if ( it != handlers.end() ) {
    it->second->handle();
  }
}
void SimpleRESTManager::register_handler(std::string name, SimpleRESTHandler* handler) {
  handlers[name] = handler;
}
