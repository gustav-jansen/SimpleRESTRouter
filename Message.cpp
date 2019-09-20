#include "Message.hpp"

Message::~Message() {
  delete buffer;
}

Message::Message(int number_of_bytes) {
  buffer = new char[number_of_bytes];
  //buffer = {0};
}
