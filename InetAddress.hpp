#ifndef InetAddress_hpp
#define InetAddress_hpp

#include <netinet/in.h>
#include <string>

class InetAddress {
private:
  struct sockaddr_in stored_address;

public:
  // Constructors & deconstructors
  InetAddress(int);
  InetAddress(std::string, int);
  ~InetAddress();

  struct sockaddr *get_sockaddr(void);
  void set_address(int);
  void set_address(std::string, int);

  void set_sin_family(void); 
  void set_sin_addr(unsigned long address);
  void set_sin_addr(std::string hostname);
  void set_sin_port(int port);
};
#endif
