#include "InetAddress.hpp"

#include <unistd.h>
#include <arpa/inet.h>

InetAddress::~InetAddress() {}

InetAddress::InetAddress(int port) {
  set_address(port);
}

InetAddress::InetAddress(std::string ip_address, int port) {
  set_address(ip_address, port);
}

struct sockaddr *InetAddress::get_sockaddr(void) {
  return (sockaddr * ) &stored_address;
}

void InetAddress::set_address(int port) {
  set_sin_family();
  set_sin_addr(INADDR_ANY);
  set_sin_port(port);
}

void InetAddress::set_address(std::string ip_address, int port) {
  set_sin_family();
  set_sin_addr(ip_address);
  set_sin_port(port);
}

void InetAddress::set_sin_family(void) {
  stored_address.sin_family = AF_INET;
}

void InetAddress::set_sin_addr(unsigned long address) {
  stored_address.sin_addr.s_addr = address;
}

void InetAddress::set_sin_addr(std::string ip_address) {
  inet_aton(ip_address.c_str(), &stored_address.sin_addr);
}

void InetAddress::set_sin_port(int port) {
  stored_address.sin_port = htons(port);
}
