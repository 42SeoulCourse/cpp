#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << "WrongCat created. Default." << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) {
  std::cout << "Copy constructor called. " << std::endl;
  *this = src;
}

WrongCat::~WrongCat(void) { std::cout << "WrongCat destroyed." << std::endl; }

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
  if (this != &rhs) {
    _type = rhs.getType();
  }
  return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << "wrong.. meee❗️" << std::endl;
}
