#ifndef SocketListener_hpp
#define SocketListener_hpp

#define DEFAULT_QUEUE_DEPTH 5

#include "InetAddress.hpp"
#include "Message.hpp"
#include <string>

class SocketListener {
private:
  InetAddress *listener_address;
  int listener_socket, queue_depth;

public:
  SocketListener();
  SocketListener(int);
  SocketListener(std::string, int);
  ~SocketListener();

  void set_queue_depth(int);
  void start_listening(void);
  int create_socket(void);
  void bind_to_address(int, struct sockaddr*);
  void listen_for_connections(int, int);
  Message *get_next_message(void);
  int accept_a_connection(int, struct sockaddr*);
};
#endif
