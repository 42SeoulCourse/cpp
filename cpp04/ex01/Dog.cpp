#include "./Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
  std::cout << "[ " << this->_type << " ] created. Default." << std::endl;
  brain = new Brain();
}

Dog::Dog(const Dog& src) {
  std::cout << "[ " << this->_type << " ] copy constructor called. " << std::endl;
  *this = src;
}

Dog::~Dog(void) {
  delete this->brain;
  std::cout << "[ " << this->_type << " ] destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
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

void Dog::makeSound(void) const { std::cout << "meong meong ~ !! 🐩" << std::endl; }

Brain* Dog::getBrain(void) const { return brain; }
