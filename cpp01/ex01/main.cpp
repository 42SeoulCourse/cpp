#include "./Zombie.hpp"

int main(void)
{
    int zombiesNumber = 3;
    std::string name = "ywee";
    Zombie *new_zombies = zombieHorde(zombiesNumber, name);
    delete [] new_zombies;
    return (0);
}