#include "SocketListener.hpp"

#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "SimpleHTTPParser.hpp"

SocketListener::~SocketListener() {
  close(listener_socket);
}

SocketListener::SocketListener() {}
SocketListener::SocketListener(int port) {
  listener_address = new InetAddress(port);
  start_listening();
}

SocketListener::SocketListener(std::string ip_address, int port) {
  listener_address = new InetAddress(ip_address, port);
  start_listening();
}

void SocketListener::set_queue_depth(int new_queue_depth) {
  queue_depth = new_queue_depth;
}

void SocketListener::start_listening(void) {
  listener_socket = create_socket();
  bind_to_address(listener_socket, listener_address->get_sockaddr());
  listen_for_connections(listener_socket, queue_depth);
}

int SocketListener::create_socket(void) {
  int asocket, opt=1;

  if ((asocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  if (setsockopt(asocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
      &opt, sizeof(opt))) {
    perror("setsockopt"); 
    exit(EXIT_FAILURE); 
    } 
  return asocket;
}

void SocketListener::bind_to_address(int asocket, struct sockaddr *address) {

  if (bind(asocket, address, (socklen_t) sizeof(*address)) < 0 ) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
}

void SocketListener::listen_for_connections(int asocket, int queue_depth) {
  if (listen(asocket, queue_depth) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
}

Message *SocketListener::get_next_message(void) {
  int asocket, buffer_length=1024, number_of_bytes_read;
  Message *msg;
  SimpleHTTPParser parser;
  std::string response;

  msg = new Message(buffer_length);

  asocket = accept_a_connection(listener_socket, listener_address->get_sockaddr());
  number_of_bytes_read = read(asocket , msg->buffer, buffer_length);
  if ( number_of_bytes_read < 0 ) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  response = parser.get_http_version(msg) + " 204 \n\n";
  send(asocket, response.c_str(), response.length(), 0);
  close(asocket);
  return msg;
}


int SocketListener::accept_a_connection(int listener, struct sockaddr *address) {
    socklen_t addrlen = (socklen_t) sizeof(*address);

  int asocket;
  if ((asocket = accept(listener, address, &addrlen))<0)
    {
      perror("accept");
      exit(EXIT_FAILURE);
    }
  return asocket;
}
