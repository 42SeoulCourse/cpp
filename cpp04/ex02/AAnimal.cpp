#include "./AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Default") {
    std::cout << "AAnimal created. Default" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
    std::cout << "[ " << type << " ] created by AAnimal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
    std::cout << "AAnimal' Copy constructor called" << std::endl;
    *this = src;
}

AAnimal::~AAnimal(void) {
    std::cout << "AAnimal destroyed" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
    if (this != &rhs) {
      this->_type = rhs._type;
    }
    return *this;
}

std::string AAnimal::getType() const { return this->_type; }
