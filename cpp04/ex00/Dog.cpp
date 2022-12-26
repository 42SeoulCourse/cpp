#include "./Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
  std::cout << "[ " << this->_type << " ] created. Default." << std::endl;
}

Dog::Dog(const Dog& src) {
  std::cout << " [" << this->_type << " ] copy constructor called. "
            << std::endl;
  *this = src;
}

Dog::~Dog(void) {
  std::cout << "[ " << this->_type << " ] destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
  if (this != &rhs) {
    _type = rhs.getType();
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "meong meong ~ !! 🐩" << std::endl; }