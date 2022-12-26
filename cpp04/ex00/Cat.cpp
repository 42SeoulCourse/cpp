#include "./Cat.hpp"

Cat::Cat(void) : Animal("Default") {
  std::cout << "Cat created. Default." << std::endl;
}

Cat::Cat(const Cat& src) {
  std::cout << "Cat copy constructor called. " << std::endl;
  *this = src;
}

Cat::~Cat(void) { std::cout << "Cat destroyed." << std::endl; }

Cat& Cat::operator=(const Cat& rhs) {
  if (this != &rhs) {
    _type = rhs.getType();
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "meow meow ~ 😾" << std::endl; }