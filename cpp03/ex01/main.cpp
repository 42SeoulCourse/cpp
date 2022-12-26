#include "./ScavTrap.hpp"

int main() {
  ClapTrap a("Jaekim");
  ScavTrap b("malibu");

//   멤버 변수 값 확인
  std::cout << "name : " << a << std::endl;
  std::cout << "hitpoints : " << a.getHitPoints() << std::endl;
  std::cout << "energy points : " << a.getEnergyPoints() << std::endl;
  std::cout << "attack damage : " << a.getAttackDamage() << std::endl;
  //
  std::cout << "name : " << b << std::endl;
  std::cout << "hitpoints : " << b.getHitPoints() << std::endl;
  std::cout << "energy points : " << b.getEnergyPoints() << std::endl;
  std::cout << "attack damage : " << b.getAttackDamage() << std::endl;
  b.guardGate();
  //
  a.attack("jaekim");
  b.takeDamage(20);

  std::cout << "name : " << a << std::endl;
  std::cout << "hitpoints : " << a.getHitPoints() << std::endl;
  std::cout << "energy points : " << a.getEnergyPoints() << std::endl;
  std::cout << "attack damage : " << a.getAttackDamage() << std::endl;
  //
  std::cout << "name : " << b << std::endl;
  std::cout << "hitpoints : " << b.getHitPoints() << std::endl;
  std::cout << "energy points : " << b.getEnergyPoints() << std::endl;
  std::cout << "attack damage : " << b.getAttackDamage() << std::endl;
  return (0);
}
