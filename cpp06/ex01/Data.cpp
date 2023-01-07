#include "Data.hpp"

Data::Data(void) : _data("") { 
  // std::cout << "Data created. Default." << std::endl; 
}

Data::Data(const Data & src) { 
  // std::cout << "Copy constructor called. " << std::endl; 
   *this = src; 
}

Data::~Data(void) { 
  // std::cout << "Data destroyed." << std::endl; 
}

Data & Data::operator=(const Data & rhs) {
  if (this != &rhs) {
    this->_data = rhs._data;
  }
  return *this;
}

void Data::setData(std::string str) {
	this->_data = str;
}

std::string Data::getData() const {
	return this->_data;
}