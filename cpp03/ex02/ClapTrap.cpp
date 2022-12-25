#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << "Default ClapTrap constructor called" << std::endl;
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
  // this 를 확인하는 조건문이 필요할까?
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
// 공격 시 hit point 가 0 일 때 (체력)
// 공격 시 energy point 가 0일 때 (공격 시 필요한 에너지)
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

// 공격 받기 전, hit point 가 이미 0 일 때
// 공격 받았을 시, hit point 가 0 이하가 될 때
// 공격 받았을 시, hit point 가 1 이상이 될 때
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

// - ClapTrap 이 공격하면, 타겟은 <attack damage> 만큼 hit points 를 잃는다.
// - ClapTrap 이 스스로 고치면, <amount> 만큼 hit points 를 를 얻는다.
// - 공격과 수리는 각각 1 에너지 비용이 든다. ClapTrap은 hit points 나 energy
// points 가 없으면 아무것도 할 수 없다.
// - 모든 멤버 함수는 어떤 일이 일어나는지 메시지를 출력한다.
//     - ex) attack()

//         ClapTrap <name> attacks <target>, causing <damage> points of damage!

// - 생성자들과 소멸자 또한 메시지를 출력한다.
// - 올바르게 작동하는지 테스트를 만들고 실행해라.

// void attack(const std::string &target);
// void takeDamage(unsigned int amount);
// void beRepaired(unsigned int amount);