#include "HumanB.hpp"

HumanB::HumanB(void) {
  std::cout << "HumanB created. Default." << std::endl;
  return;
}

HumanB::~HumanB(void) { std::cout << "HumanB destroyed" << std::endl; }

HumanB::HumanB(std::string name) : _name(name) {
  this->_weapon = NULL;
  return;
}

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

void HumanB::attack(void) const {
  if (!_weapon) {
    std::cout << this->_name << " has no weapon " << std::endl;
  } else if (!_weapon->getType().length()) {
    std::cout << this->_name << " has no weapon " << std::endl;
  } else {
    std::cout << this->_name << " attacks with their " << (*_weapon).getType()
              << std::endl;
  }
  return;
}