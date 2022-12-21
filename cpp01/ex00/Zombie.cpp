#include "./Zombie.hpp"

Zombie::Zombie( void )
{
    std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << _name << " created " << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << _name << " : BraiiiiiiinnnzzzZ…" << std::endl;
}

Zombie *newZombie(std::string name)
{
    Zombie *new_zombie = new Zombie(name);
    return new_zombie;
}

void    randomChump(std::string name)
{
    Zombie newZombie(name);
    newZombie.announce();
    return ;
}