#include <thread>
#include <chrono>

#include "SimpleRESTHandler.hpp"
#include "SimpleRESTManager.hpp"

int main(int argc, char const *argv[])
{
  SimpleRESTManager * manager;
  SimpleRESTHandler *handler = new SimpleRESTHandler();

  manager = new SimpleRESTManager("127.0.0.1", 8080);
  manager->register_handler("/stop", handler);
  while ( not handler->has_been_called() ) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
  printf("Shutting down.\n");
  delete manager;
  delete handler;
  return 0;
}
