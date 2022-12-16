#include "./Zombie.hpp"

Zombie::Zombie( void )
{
    std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << _name << " : BraiiiiiiinnnzzzZ…" << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
    return;
}

Zombie *zombieHorde(int N, std::string name)
{
    Zombie  *zombie = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombie[i].setName(name);
        zombie[i].announce();
    }
    return (zombie);
}
