#include "./Cat.hpp"

Cat::Cat(void) : AAnimal("Cat") {
  std::cout << "[ " << this->_type << " ] created. Default." << std::endl;
  brain = new Brain();
}

Cat::Cat(const Cat& src) {
  std::cout << "[ " << this->_type << " ] copy constructor called. " << std::endl;
  *this = src;
}

Cat::~Cat(void) {
  delete this->brain;
  std::cout << "[ " << this->_type << " ] destroyed." << std::endl;
}

Cat& Cat::operator=(const Cat &rhs) {
  if (this != &rhs) {
    _type = rhs.getType();
    if (this->brain) {
      delete brain;
      brain = NULL;
    }
    brain = new Brain(*rhs.brain);
  }
  return *this;
}

void Cat::makeSound(void) const { std::cout << "meow meow ~ 😾" << std::endl; }

Brain* Cat::getBrain(void) const { return brain; }