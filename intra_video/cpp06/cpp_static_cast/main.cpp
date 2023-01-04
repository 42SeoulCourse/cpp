#include <iostream>

class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};

class Unrelated {};

int main(void) {
  Child1  a;

  Parent *b = &a;           // Implicit upcast cast
  // Child1 *c = b;            // Implicit downcast -> No!
  Child2 *d = static_cast<Child2 *>(b); // Explicit downcast

  // Unrelated *e = static_cast<Child2 *>(b); // Explicit conversion -> No
  return 0;
}