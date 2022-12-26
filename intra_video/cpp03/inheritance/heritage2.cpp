#include <iostream>

class Animal {
 private:
  int _numberOfLegs;

 public:
  Animal();
  Animal(const Animal &);
  Animal &operator=(const Animal &);
  ~Animal();

  void run(int distance);
  void call();
  void eat(const std::string &what);
  void walk(int distance);
};

class Cat : public Animal {
 public:
  Cat();
  Cat(Cat const &);
  Cat &operator=(const Cat &);
  ~Cat();

  void scornSameone(const std::string &target);
};

class Pony : public Animal {
 public:
  Pony(void);
  Pony(const Pony &src);
  virtual ~Pony(void);
  Pony &operator=(const Pony &rhs);

  void doMagic(const std::string &target);
  void run(int distance); // 부모에 같은 이름이 있지만 재정의
};
