// #include "PhoneBook.class.hpp"
// #include "Contact.class.hpp"
#include <iostream>
#include <string>
#include <cctype>

int main(void)
{
    std::string cmd;
    // PhoneBook pb;
    int i = 0;

    while (true)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, cmd);
        cmd.erase(0, cmd.find_first_not_of(" \t\v\f\r"));
        // while (isspace(cmd[cmd.length() - 1]))
        //     cmd.erase(cmd.find_last_not_of(" \t\v\f\r") + 1, cmd[cmd.length() - 1]);
        std::cout << cmd << std::endl;
        if (cmd == "EXIT")
            break ;
    }
    
    return (0);
}