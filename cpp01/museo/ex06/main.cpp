#include "./Harl.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "usage: ./harlFilter <LEVEL>" << std::endl;
    exit(1);
  }

  Harl harl;
  harl.Harl::complainFilter(av[1]);
  return (0);
}
