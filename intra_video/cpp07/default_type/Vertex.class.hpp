#include <iomanip>
#include <iostream>

template <typename T = float>
class Vertex {
 private:
  T const _x;
  T const _y;
  T const _z;

  // 기본 생성자를 private으로 한 의미는
  // 매개 변수 없이는 생성할 수 없게 하기 위함이다.
  Vertex(void);

 public:
  Vertex(T const &x, T const &y, T const &z) : _x(x), _y(y), _z(z) {}
  ~Vertex(void) {}

  T const &getX() const{return this->_x;}
  T const &getY() const{return this->_y;}
  T const &getZ() const{return this->_z;}
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Vertex<T> const &v) {
  std::cout.precision(1);
  o << std::setiosflags(std::ios::fixed);
  o << "Vertex( ";
  o << v.getX() << ", ";
  o << v.getY() << ", ";
  o << v.getZ() << "";
  o << " )";
  return o;
}