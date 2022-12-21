#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int j;

    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    for (int i = 1; i < ac; i++)
    {
        j = 0;
        while (av[i][j])
        {
            std::cout << (char) std::toupper(av[i][j]);
            j++;
        }
    }
    std::cout << std::endl;
    return (0);
}