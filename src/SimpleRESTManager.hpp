#ifndef SimpleRESTManager_hpp
#define SimpleRESTManager_hpp

#define DEFAULT_PORT 8080

#include <string>
#include <thread>
#include <map>
#include <functional>

#include "SocketListener.hpp"
#include "SimpleRESTHandler.hpp"

class SimpleRESTManager {
  SocketListener *listener;
  std::map<std::string, SimpleRESTHandler*> handlers;

public:
  SimpleRESTManager();
  SimpleRESTManager(std::string ip_adress, int port);
  ~SimpleRESTManager();
  void message_loop(void);
  void register_handler(std::string, SimpleRESTHandler*);
  void handle_command(std::string);
};
#endif
