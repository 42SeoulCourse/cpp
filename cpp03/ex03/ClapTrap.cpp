#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << "[ " << name << " ] is created from ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const std::string name, unsigned int hit_points,
                   unsigned int energy_points, unsigned int attack_damage)
    : _name(name),
      _hit_points(hit_points),
      _energy_points(energy_points),
      _attack_damage(attack_damage) {
  std::cout << "[ " << name << " ] is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
  if (this != &rhs) {
    _name = rhs._name;
    _hit_points = rhs._hit_points;
    _energy_points = rhs._energy_points;
    _attack_damage = rhs._energy_points;
  }
  return *this;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "Destructor ClapTrap called name : [ " << this->_name << " ]"
            << std::endl;
  return;
}

std::ostream &operator<<(std::ostream &o, const ClapTrap &claptrap) {
  o << claptrap.getName();
  return (o);
}

const std::string ClapTrap::getName(void) const { return (this->_name); }
unsigned int      ClapTrap::getHitPoints() const { return (this->_hit_points); }
unsigned int      ClapTrap::getEnergyPoints() const {
  return (this->_energy_points);
}
unsigned int ClapTrap::getAttackDamage() const {
  return (this->_attack_damage);
}

void ClapTrap::attack(const std::string &target) {
  if (this->_hit_points == 0 || this->_energy_points == 0) {
    std::cout << "ClapTrap " << this->_name
              << " can't attack target ! (No hit Points or energy Points)"
              << "\n( Hit Points : " << this->_hit_points
              << ", Energy Points : " << this->_energy_points << " )"
              << std::endl
              << std::endl;
    return;
  }
  --(this->_energy_points);
  std::cout << "ClapTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack_damage << " points of damage!"
            << std::endl
            << std::endl;
  return;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->_hit_points == 0) {
    std::cout << "ClapTrap " << this->_name
              << " has no hit points.\n( hit points : " << this->_hit_points
              << " )" << std::endl
              << std::endl;
  } else if (this->_hit_points <= amount) {
    std::cout << "ClapTrap " << this->_name << " take " << amount
              << " damage. And hit points become under 0. \n( hit points : "
              << (int)(this->_hit_points - amount) << " and will become 0. )"
              << std::endl
              << std::endl;
    this->_hit_points = 0;
  } else {
    std::cout << "ClapTrap " << this->_name << " take " << amount
              << " damege. And hit points become " << this->_hit_points - amount
              << std::endl
              << std::endl;
    this->_hit_points -= amount;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_hit_points == 0 || this->_energy_points == 0) {
    std::cout << "ClapTrap" << this->_name
              << " can't repair. (No hit points or energy points)\n( Hit "
                 "points : "
              << this->_hit_points
              << ", Energy points : " << this->_energy_points << " )"
              << std::endl
              << std::endl;
    return;
  }
  --(this->_energy_points);
  std::cout << "ClapTrap " << this->_name << " repaired hit points "
            << this->_hit_points << " to " << this->_hit_points + amount
            << std::endl
            << std::endl;
  this->_hit_points += amount;
}
