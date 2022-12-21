#include "./Zombie.hpp"

int main(void)
{
    Zombie *new_zombie = newZombie("jaekim");
    new_zombie->announce();
    delete new_zombie;
    randomChump("I am Groot");
    return (0);
}