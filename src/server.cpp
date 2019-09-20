#include "SimpleRESTManager.hpp"

#include <thread>
#include <chrono>

bool shutdown_flag;

void stop_handler(void) {
  shutdown_flag = true;
}

int main(int argc, char const *argv[])
{
  SimpleRESTManager * manager;

  shutdown_flag = false;
  manager = new SimpleRESTManager("127.0.0.1", 8080);
  manager->register_handler("/stop", stop_handler);
  while ( not shutdown_flag ) {
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
  printf("Shutting down.\n");
  delete manager;
  return 0;
}
