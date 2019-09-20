#include "SimpleHTTPParser.hpp"

#include <sstream>
#include <vector>
#include <iterator>

std::string SimpleHTTPParser::get_request_target(Message *msg) {
  std::istringstream stream(get_start_line(msg));

  std::vector<std::string> words((std::istream_iterator<std::string>(stream)),
                                 std::istream_iterator<std::string>());
  return words[1];
    
}

std::string SimpleHTTPParser::get_start_line(Message *msg) {
    std::string line;

    std::istringstream stream(msg->buffer);
    std::getline(stream, line);
    return line;
}
