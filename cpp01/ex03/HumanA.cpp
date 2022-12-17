#include "HumanA.hpp"

HumanA::~HumanA(void) { std::cout << "HumanA destroyed" << std::endl; }

HumanA::HumanA(std::string name, Weapon &type) : _name(name), _Weapon(type) {
  return;
}

void HumanA::attack(void) const {
  std::cout << this->_name << " attacks with their " << _Weapon.getType()
            << std::endl;
  return;
}