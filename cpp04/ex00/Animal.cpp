#include "./Animal.hpp"

Animal::Animal(void) : _type("Default") {
    std::cout << "Animal created. Default" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << "[ " << type << " ] created." << std::endl;
}

Animal::Animal(const Animal &src) {
    std::cout << "Animal' Copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal(void) {
    std::cout << "Animal destroyed" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
    if (this != &rhs) {
      this->_type = rhs._type;
    }
    return *this;
}

std::string Animal::getType() const { return this->_type; }

void    Animal::makeSound() const {
    std::cout << "I have no specific sound." << std::endl;
}