#ifndef SimpleRESTHandler_hpp
#define SimpleRESTHandler_hpp

enum HandlerState { called, not_called };

class SimpleRESTHandler {
private:
  HandlerState state;

public:
  SimpleRESTHandler() {
    reset();
  }

  void reset(void) {
    state = not_called;
  }

  void handle(void) {
    state = called;
  }

  bool has_been_called(void) {
    return state == called;
  }
};
#endif
