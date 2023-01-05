#include "Conversion.hpp"

Conversion::Conversion(void)
    : _input(NULL),
      _c(0),
      _i(0),
      _f(0.0f),
      _d(0.0),
      _char(""),
      _int(""),
      _float(""),
      _double("") {
  // std::cout << "Conversion created. Default." << std::endl;
}

Conversion::Conversion(std::string input)
    : _input(input),
      _c(0),
      _i(0),
      _f(0.0f),
      _d(0.0),
      _char(""),
      _int(""),
      _float(""),
      _double("") {
  // std::cout << "Conversion created. Default." << std::endl;
}

Conversion::Conversion(const Conversion& src) {
  // std::cout << "Copy constructor called. " << std::endl;
  *this = src;
}

Conversion::~Conversion(void) {
  // std::cout << "Conversion destroyed." << std::endl;
}

Conversion& Conversion::operator=(const Conversion& rhs) {
  if (this != &rhs) {
    this->_input = rhs._input;
    this->_c = rhs._c;
    this->_i = rhs._i;
    this->_f = rhs._f;
    this->_d = rhs._d;
  }
  return *this;
}

const bool Conversion::isPseudo(std::string input) {
  // +inf?? inf??
  static const std::string pseudo[6] = {"-inf",  "inf",  "nan",
                                        "-inff", "inff", "nanf"};

  for (int i = 0; i < 6; i++) {
    if (input.compare(pseudo[i])) {
      _char = "impossible";
      _int = "impossible";
      _float = pseudo[i];
      _double = pseudo[i];
      return true;
    }
  }
  return false;
}

const int Conversion::getType() {
  if (isPseudo(_input)) {
    return PSEUDO;
  }
  if (_input.length() == 1 && std::isdigit()) {

  }
}

void Conversion::convert(void) {
  displayChar();
  displayInt();
  displayFloat();
  displayDouble();
}

void Conversion::displayChar(void) const {}

void Conversion::displayInt(void) const {}

void Conversion::displayFloat(void) const {}

void Conversion::displayDouble(void) const {}