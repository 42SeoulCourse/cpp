#include "Conversion.hpp"

Conversion::Conversion(void)
    : _input(""), _i(0), _f(0), _c(0), _d(0), _type(INVALID), _isWrong(false) {
  return;
}

Conversion::Conversion(const Conversion &src) { *this = src; }

Conversion &Conversion::operator=(Conversion const &rhs) {
  if (this != &rhs) {
    _input = rhs._input;
    _c = rhs._c;
    _i = rhs._i;
    _f = rhs._f;
    _d = rhs._d;
    _type = rhs._type;
    _isWrong = rhs._isWrong;
  }
  return *this;
}

Conversion::~Conversion(void) { return; }

void Conversion::setInput(const std::string &argv) { this->_input = argv; }

bool Conversion::isPseudo(std::string str) {
  if (str == "nan" || str == "nanf" || str == "+inff" || str == "-inff" ||
      str == "-inf" || str == "+inf")
    return true;
  return false;
}

void Conversion::detectType(char *argv) {
  this->setInput(std::string(argv));
  int i = 0;
  int is_dot = 0;
  int is_float = 0;
  int is_letter = 0;
  int is_number = 0;
  int is_minus = 0;

  if (isPseudo(this->_input) == true) {
    this->setType(PSEUDO);
    return;
  }

  while (argv[i]) {
    if (argv[i] == '-' && i == 0) {
      is_minus = 1;
    } else if (std::isdigit(argv[i])) {
      is_number = 1;
    } else if (argv[i] == '.')
      is_dot = 1;
    if (std::isalpha(argv[i])) is_letter = 1;
    i++;
  }
  if (i == 1) {
    this->setType(CHAR_TYPE);
    this->_c = atoi(this->_input.c_str());
  } else if (is_number == 1 && is_dot == 1 && is_float == 1) {
    this->setType(FLOAT_TYPE);
    this->_f = std::stof(this->_input);
  } else if (is_number == 1 && is_dot == 1 && is_float == 0) {
    this->setType(DOUBLE_TYPE);
    this->_d = std::stod(this->_input);
  } else if (is_number == 1 && is_dot == 0 && is_float == 0 && is_letter == 0) {
    this->setType(INT_TYPE);
    if (std::stol(this->_input) >= INT_MIN &&
        std::stol(this->_input) <= INT_MAX) {
      this->_i = std::stoi(this->_input);
      this->_c = this->_i;
    } else {
      this->_isWrong = true;
    }
  } else {
    this->setType(INVALID);
  }
}

int Conversion::getType() const { return this->_type; }
const std::string &Conversion::getInput() const { return _input; }

void Conversion::convertData() {
  switch ((this->getType())) {
    case FLOAT_TYPE:
      this->_c = static_cast<char>(this->_f);
      this->_d = static_cast<double>(this->_f);
      this->_i = static_cast<int>(this->_f);
      break;
    case INT_TYPE:
      this->_f = static_cast<float>(this->_i);
      this->_c = static_cast<char>(this->_i);
      this->_d = static_cast<double>(this->_i);
      break;
    case DOUBLE_TYPE:
      this->_c = static_cast<char>(this->_d);
      this->_f = static_cast<float>(this->_d);
      this->_i = static_cast<int>(this->_d);
      break;
    case CHAR_TYPE:
      this->_i = static_cast<int>(this->_c);
      this->_d = static_cast<double>(this->_c);
      this->_f = static_cast<float>(this->_c);
      break;
    default:
      break;
  }
}

void Conversion::getChar() const {
  std::cout << "char: ";
  if (_type == PSEUDO) {
    std::cout << "impossible" << std::endl;
  } else if (_c >= 32 && _c <= 126) {
    std::cout << _c << std::endl;
  } else {
    std::cout << "Non displayable" << std::endl;
  }
}

void Conversion::getInt() const {
  std::cout << "int: ";
  if (_type == PSEUDO || _type == INVALID) {
    std::cout << "impossible" << std::endl;
  } else if (_isWrong == true) {
    std::cout << "overflow" << std::endl;
  } else {
    std::cout << _i << std::endl;
  }
}

void Conversion::getFloat() const {
  std::cout << "float: ";
  if (_type == PSEUDO) {
    if (_input == "-inf" || _input == "+inf" || _input == "nan") {
      std::cout << _input << "f" << std::endl;
    } else {
      std::cout << _input << std::endl;
    }
  } else if (_type == INVALID) {
    std::cout << "impossible" << std::endl;
  } else if (std::stol(_input) >= INT_MIN && std::stol(_input) <= INT_MAX) {
    std::cout << std::fixed << std::setprecision(1) << _f << "f" << std::endl;
  } else {
    std::cout << _input << "f" << std::endl;
  }
}

void Conversion::getDouble() const {
  std::cout << "double: ";
  if (_type == PSEUDO) {
    std::cout << convertLiteralToDouble(_input) << std::endl;
  } else if (_type == INVALID) {
    std::cout << "impossible" << std::endl;
  } else if (std::stol(_input) >= INT_MIN && std::stol(_input) <= INT_MAX) {
    std::cout << std::fixed << std::setprecision(1) << _d << std::endl;
  } else {
    std::cout << _input << std::endl;
  }
}

void Conversion::printData() const {
  getChar();
  getInt();
  getFloat();
  getDouble();
}

void Conversion::setType(int type) { this->_type = type; }

std::string convertLiteralToDouble(std::string input) {
  if (input == "nanf") return "nan";
  if (input == "+inff") return "+inf";
  if (input == "-inff") return "-inf";
  return input;
}

