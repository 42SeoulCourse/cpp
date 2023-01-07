#include <iostream>
#include <typeinfo>
#include <exception>

class Parent {public: virtual ~Parent(void) {}};
class Child1 : public Parent {};
class Child2 : public Parent {};

int main(void) {
  Child1  a;
  Parent *b = &a; // Implicit upcast -> Ok

  //Explicit downcast
  Child1 *c = dynamic_cast<Child1 *>(b);
  if ( c == NULL ) {
    std::cout << "conversion is NOT Ok" << std::endl;
  }
  else {
    std::cout << "conversion is Ok" << std::endl;
  }

  //Explicit downcast
  try {
    Child2 &d = dynamic_cast<Child2 &>(*b);
    std::cout << "conversion is Ok" << std::endl;
  } catch (std::bad_cast &bc) {
    std::cout << "conversion is NOT Ok: " << bc.what() << std::endl;
    return 0;
  }
  return 0;
}