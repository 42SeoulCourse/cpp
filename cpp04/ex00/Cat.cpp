#include "./Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
  std::cout << "[ " << this->_type << " ] created. Default." << std::endl;
}

Cat::Cat(const Cat& src) {
  std::cout << " [" << this->_type << " ] copy constructor called. "
            << std::endl;
  *this = src;
}

Cat::~Cat(void) {
  std::cout << "[ " << this->_type << " ] destroyed." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
  if (this != &rhs) {
    _type = rhs.getType();
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "meow meow ~ 😾" << std::endl; }