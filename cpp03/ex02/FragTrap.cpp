#include "./FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default", 100, 100, 30) {
  std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
  std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  if (this != &rhs) {
    _name = rhs._name;
    _hit_points = rhs._hit_points;
    _energy_points = rhs._energy_points;
    _attack_damage = rhs._energy_points;
  }
  return *this;
}

FragTrap::~FragTrap(void) {
  std::cout << "Destructor FragTrap called name : [ " << this->_name << " ]"
            << std::endl;
  return;
}

std::ostream &operator<<(std::ostream &o, const FragTrap &flagtrap) {
  o << flagtrap.getName();
  return (o);
}

void FragTrap::attack(const std::string &target) {
  if (this->_hit_points == 0 || this->_energy_points == 0) {
    std::cout << "FragTrap " << this->_name
              << " can't attack target ! (No hit Points or energy Points)"
              << "\n( Hit Points : " << this->_hit_points
              << ", Energy Points : " << this->_energy_points << " )"
              << std::endl
              << std::endl;
    return;
  }
  --(this->_energy_points);
  std::cout << "FragTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack_damage << " points of damage!"
            << std::endl
            << std::endl;
  return;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "[ " << this->_name << " ]: positive high fives request 👋"
            << std::endl;
}
