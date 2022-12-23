#include "Weapon.hpp"

Weapon::Weapon(void) { std::cout << "Weapon created.  Default." << std::endl; }

Weapon::~Weapon(void) { std::cout << "Weapon destroyed" << std::endl; }

Weapon::Weapon(const std::string type) : _type(type) {
  std::cout << "Weapon [ " << type << " ] is Created" << std::endl;
  return;
}

Weapon::Weapon(void *a) {
  if (!a) return;
}

const std::string& Weapon::getType(void) const { return this->_type; }

void Weapon::setType(std::string type) {
  this->_type = type;
  return;
}
