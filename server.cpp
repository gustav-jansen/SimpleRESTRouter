#include "SimpleRESTManager.hpp"

int main(int argc, char const *argv[])
{
  SimpleRESTManager * manager;

  manager = new SimpleRESTManager("127.0.0.1", 8080);
  return 0;
}
