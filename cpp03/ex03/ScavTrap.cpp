#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20) {
  std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
  std::cout << "Default ScavTrap constructor called [ " << this->_name << " ]"
            << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  if (this != &rhs) {
    _name = rhs._name;
    _hit_points = rhs._hit_points;
    _energy_points = rhs._energy_points;
    _attack_damage = rhs._energy_points;
  }
  return *this;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "Destructor ScavTrap called name : [ " << this->_name << " ]"
            << std::endl;
  return;
}

void ScavTrap::setEnergyPoints(void) { this->_energy_points = 50; }

std::ostream &operator<<(std::ostream &o, const ScavTrap &scavtrap) {
  o << scavtrap.getName();
  return (o);
}

void ScavTrap::attack(const std::string &target) {
  if (this->_hit_points == 0 || this->_energy_points == 0) {
    std::cout << "ScavTrap " << this->_name
              << " can't attack target ! (No hit Points or energy Points)"
              << "\n( Hit Points : " << this->_hit_points
              << ", Energy Points : " << this->_energy_points << " )"
              << std::endl
              << std::endl;
    return;
  }
  --(this->_energy_points);
  std::cout << "ScavTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack_damage << " points of damage!"
            << std::endl
            << std::endl;
  return;
}

void ScavTrap::guardGate(void) {
  std::cout << "[ " << this->_name << " ] now in Gate keeper mode!"
            << std::endl;
}
