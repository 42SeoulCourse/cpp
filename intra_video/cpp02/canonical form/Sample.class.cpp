#include "Sample.class.hpp"
#include <iostream>

Sample::Sample(void) : _foo(0) {
  std::cout << "Sample created. Default." << std::endl;
}

Sample::~Sample(void) { std::cout << "Sample destroyed." << std::endl; }

Sample::Sample(int const n) : _foo(n) {
  std::cout << "Parametric Constructor called" << std::endl;
}

Sample::Sample(const Sample& src) {
  std::cout << "Copy constructor called." << std::endl;
  *this = src;
}

Sample& Sample::operator=(const Sample& rhs) {
  std::cout << "Assignment operator called" << std::endl;
  if (this != &rhs) {
    this->_foo = rhs.getFoo();
  }
  return *this;
}

std::ostream & operator<<(std::ostream &o, Sample const & i) {
  o << "The value of _foo is : " << i.getFoo();
  return o;
}

int Sample::getFoo(void) const { return this->_foo; }