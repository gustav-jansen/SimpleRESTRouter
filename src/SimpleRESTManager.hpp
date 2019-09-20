#ifndef SimpleRESTManager_hpp
#define SimpleRESTManager_hpp

#define DEFAULT_PORT 8080

#include <string>
#include <thread>
#include <map>
#include <functional>

#include "SocketListener.hpp"

class SimpleRESTManager {
  SocketListener *listener;
  std::map<std::string, std::function<void()>> handlers;

public:
  SimpleRESTManager();
  SimpleRESTManager(std::string ip_adress, int port);
  ~SimpleRESTManager();
  void message_loop(void);
  void register_handler(std::string, std::function<void()>);
  void handle_command(std::string);
};
#endif
