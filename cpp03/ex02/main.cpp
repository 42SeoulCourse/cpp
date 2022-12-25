#include "./FragTrap.hpp"

int main(){
    FragTrap frag("frag");

    std::cout << "hitpoints : " << frag.getHitPoints() << std::endl;
    std::cout << "energy points : " << frag.getEnergyPoints() << std::endl;
    std::cout << "attack damage : " << frag.getAttackDamage() << std::endl;

    frag.highFivesGuys();

    ClapTrap *a = &frag;
    a->attack("target");

}

