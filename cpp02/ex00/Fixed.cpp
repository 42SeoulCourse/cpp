#include "./Fixed.hpp"

Fixed::Fixed(void) : _integer(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
  return;
}

Fixed::Fixed(Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed &Fixed::operator=(Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_integer = fixed.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_integer);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_integer = raw;
}