#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
  std::cout << "Diamond Trap created. default" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name + "_clap_name"),
      FragTrap(name + "_clap_name") {
  this->_name = name;
  this->FragTrap::setHitPoints();
  this->ScavTrap::setEnergyPoints();
  this->FragTrap::setAttackDamage();
  std::cout << "DiamondTrap created [ name : " << name << " ]" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
  *this = src;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destroyed [ name : " << _name << " ]" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src) {
  if (this != &src) {
    _name = src._name;
    _hit_points = src._hit_points;
    _energy_points = src._energy_points;
    _attack_damage = src._attack_damage;
  }
  return *this;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "My name is " << _name << " and ClapTrap::name is "
            << ClapTrap::getName() << std::endl;
}
