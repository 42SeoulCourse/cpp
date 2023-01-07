#include <iomanip>
#include <iostream>

// 일반적인 템블릿
template <typename T, typename U>
class Pair {
 public:
  Pair<T, U>(T const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) {
    std::cout << "Generic template" << std::endl;
    return;
  }

  ~Pair<T, U>(void) {}
  T const &a(void) const { return this->_lhs; }
  U const &b(void) const { return this->_rhs; }

 private:
  T const &_lhs;
  U const &_rhs;

  Pair<T, U>(void);
};

//
template <typename U>
class Pair<int, U> {
 public:
  Pair<int, U>(int lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) {
    std::cout << "Int partial template" << std::endl;
    return;
  }

  ~Pair<int, U>(void) {}
  int     a(void) const { return this->_lhs; }
  U const &b(void) const { return this->_rhs; }

 private:
  int     _lhs;
  U const &_rhs;

  Pair<int, U>(void);
};

template <>
class Pair<bool, bool> {
 public:
  Pair<bool, bool>(bool lhs, bool rhs) : _lhs(lhs), _rhs(rhs) {
    std::cout << "Bool/bool specialization" << std::endl;
    this->_n = 0;
    this->_n |= static_cast<int>(lhs) << 0;
    this->_n |= static_cast<int>(rhs) << 1;
    return;
  }

  ~Pair<bool, bool>(void) {}
  bool     a(void) const { return (this->_n & 0x01); }
  bool     b(void) const { return (this->_n & 0x02); }

 private:
  bool     _n;
  bool     _lhs;
  bool     _rhs;

  Pair<bool, bool>(void);
};

template<typename T, typename U>
std::ostream &operator<<(std::ostream &o, Pair<T,U>const &p) {
  o << "Pair( " << p.a() << ", " << p.b() << " )";
  return o;
}

std::ostream &operator<<(std::ostream &o, Pair<bool,bool>const &p) {
  o << std::boolalpha << "Pair( " << p.a() << ", " << p.b() << " )";
  return o;
}