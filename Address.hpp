#ifndef Address_hpp
#define Address_hpp

#include <string>

class Address {
public:
  virtual ~Address() = 0;
  virtual void set_address(int) = 0;
  virtual void set_address(std::string, int) = 0;
};
#endif
