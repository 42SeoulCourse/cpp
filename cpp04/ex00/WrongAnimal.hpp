#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
 protected:
  std::string _type;

 public:
  WrongAnimal(void);
  WrongAnimal(std::string _type);
  WrongAnimal(const WrongAnimal& src);
  WrongAnimal& operator=(const WrongAnimal& rhs);
  virtual ~WrongAnimal(void);

  std::string getType(void) const;
  void        makeSound(void) const;
};

#endif