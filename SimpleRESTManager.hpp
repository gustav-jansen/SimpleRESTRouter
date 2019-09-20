#ifndef SimpleRESTManager_hpp
#define SimpleRESTManager_hpp

#define DEFAULT_PORT 8080

#include <string>

#include "SocketListener.hpp"

class SimpleRESTManager {
  SocketListener *listener;

public:
  SimpleRESTManager();
  SimpleRESTManager(std::string ip_adress, int port);
  ~SimpleRESTManager();
  void message_loop(void);
};
#endif
