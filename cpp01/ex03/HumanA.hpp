#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "./Weapon.hpp"

class HumanA {
 private:
  std::string const _name;
  Weapon &_Weapon;

 public:
  HumanA(void);
  ~HumanA(void);

  HumanA(std::string name, Weapon &type);

  void attack(void) const;
};

#endif