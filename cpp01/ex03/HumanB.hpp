#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "./Weapon.hpp"

class HumanB {
 private:
  std::string const _name;
  Weapon *_weapon;

 public:
  HumanB(void);
  ~HumanB(void);

  HumanB(std::string name);
  void setWeapon(Weapon &weapon);
  void attack(void) const;
};

#endif