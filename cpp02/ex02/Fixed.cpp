#include "./Fixed.hpp"

Fixed::Fixed(void) : _n(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::Fixed(const int n) : _n(n << _fractional) {
  std::cout << "Int constructor called" << std::endl;
  return;
}

Fixed::Fixed(const float n) : _n(roundf(n * (1 << _fractional))) {
  std::cout << "Float constructor called" << std::endl;
  return;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
  return;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_n = fixed.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return (this->_n);
}

void  Fixed::setRawBits(int const raw) {
  // std::cout << "setRawBits member function called" << std::endl;
  this->_n = raw;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed) {
  o << fixed.toFloat();
  return (o);
}

int Fixed::toInt(void) const {
  return ((int)(roundf((float)this->_n / (1 << this->_fractional))));
}

float Fixed::toFloat(void) const {
  return ((float)this->_n / (1 << this->_fractional));
}

Fixed Fixed::operator+(const Fixed &fixed) const {
  return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const {
  return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const {
  return (Fixed(this->toFloat() / fixed.toFloat()));
}

bool Fixed::operator>(const Fixed &fixed) const {
  return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(const Fixed &fixed) const {
  return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(const Fixed &fixed) const {
  return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed &fixed) const {
  return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return (this->toFloat() != fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
  (this->_n)++;
  return (*this);
}

Fixed &Fixed::operator--(void) {
  (this->_n)--;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  (this->_n)++;
  return (temp);
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  (this->_n)--;
  return (temp);
}

const Fixed        &Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
  if (fixed1 >= fixed2) {
    return (fixed1);
  }
  return (fixed2);
}

const Fixed        &Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
  if (fixed1 <= fixed2) {
    return (fixed1);
  }
  return (fixed2);
}

Fixed        &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
  if (fixed1 >= fixed2) {
    return (fixed1);
  }
  return (fixed2);
}

Fixed        &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
  if (fixed1 <= fixed2) {
    return (fixed1);
  }
  return (fixed2);
}