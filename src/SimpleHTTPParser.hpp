#ifndef SimpleHTTPParser_hpp
#define SimpleHTTPParser_hpp

#include <string>
#include "Message.hpp"

class SimpleHTTPParser {
public:
  std::string get_request_target(Message *);
  std::string get_start_line(Message *);
};
#endif
