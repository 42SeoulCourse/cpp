#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <string>
#include <cctype>

int main(void)
{
    std::string cmd;
    PhoneBook pb;
    int i = 0;

    while (true)
    {
        std::cout << "Enter a cmd: ";
        std::getline(std::cin, cmd);
        cmd.erase(0, cmd.find_first_not_of(" \t\v\f\r"));
        while (isspace(cmd[cmd.length() - 1]))
            cmd.erase(cmd.find_last_not_of(" \t\v\f\r") + 1, cmd[cmd.length() - 1]);
        std::cout << cmd << std::endl;
        if (cmd == "EXIT")
            break ;
        else if (cmd == "ADD")
        {
            i = pb.check_pb(pb);
            if (i > 7)
            {
                i = -42;
                while (i == -42)
                {
                    std::cout << "Attention! Maximum number of contacts reached," << std::endl
                              << "If you continue, the oldest contact will be deleted to add the new one. (Y/N): ";
                    std::getline(std::cin, cmd);
                    cmd.erase(0, cmd.find_first_not_of(" \t\v\f\r"));
                    while (isspace(cmd[cmd.length() - 1]))
                        cmd.erase(cmd.find_last_not_of(" \t\v\r\f") + 1, cmd[cmd.length() - 1]);
                    if (cmd == "Y")
                    {
                        pb = pb.del_one(pb);
                        i = 7;
                    }
                    else if (cmd == "N")
                        i = -1;
                    else
                        std::cout << "Not valid entrance!, try again.\n";
                }
            }
            if (i >= 0)
                pb = pb.add_i(pb, i);
        }
        else if (cmd == "SEARCH")
            pb.display(pb);
        else if (cmd.empty())
            continue;
        else
            std::cout << "Not a valid Command! Try again" << std::endl;
    }
    return (0);
}