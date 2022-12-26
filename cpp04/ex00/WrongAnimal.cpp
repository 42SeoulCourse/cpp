#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Default") {
  std::cout << "WrongAnimal created. Default." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  std::cout << "[ " << type << " ] created by WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
  std::cout << "Copy constructor called. " << std::endl;
  *this = src;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal destroyed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
  if (this != &rhs) {
    _type = rhs._type;
  }
  return *this;
}

std::string WrongAnimal::getType(void) const { return _type; }

void WrongAnimal::makeSound(void) const {
  std::cout << "I'm not animal.. i'm wrong.." << std::endl;
}
