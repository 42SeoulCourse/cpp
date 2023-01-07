#include <sys/time.h>

#include "Base.hpp"

Base *generate(void) {
  srand(time(NULL));
  int random = rand();
  if (random % 3 == 0) {
    return new A();
  } else if (random % 3 == 1) {
    return new B();
  } else {
    return new C();
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "Class is A type" << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "Class is B type" << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "Class is C type" << std::endl;
  } else {
    std::cout << "Class is invalid" << std::endl;
  }
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "Class is A type" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "Class is B type" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "Class is C type" << std::endl;
    return;
  } catch (std::exception &e) {
    std::cout << "Class is invalid" << std::endl;
  }
}

int main() {
  Base *base = generate();

  identify(base);
  identify(*base);
}