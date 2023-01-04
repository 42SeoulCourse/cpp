#include <iostream>

class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};

int main(void) {
  Child1  a;

  Parent *b = &a;           // Implicit "reinterpretion" cast
  Parent *c = (Parent *)&a; // Explicit "reinterpretion" cast

  Parent *d = &a;           // Implicit upcast cast -> Ok
  // Child1 *e = d;            // Implicit downcast -> No!
  Child2 *f = (Child2 *)d;  // Explicit downcast -> 되긴하지만 할거야?
  return 0;
}