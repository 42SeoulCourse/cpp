#include "phonebook.hpp"

int main(void)
{
    phonebook user01("No", "Body", "nonick", "00000");
    phonebook user02;

    user01.print_info();
    return (0);
}