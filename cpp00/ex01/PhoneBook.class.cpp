#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
    return ;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

int PhoneBook::check_pb(PhoneBook pb)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (pb.contacts[i].isnull(pb.contacts[i]))
            break;
        i++;
    }
    return (i);
}

PhoneBook PhoneBook::del_one(PhoneBook pb)
{
    int i;

    i = 0;
    while (i < 7)
    {
        pb.contacts[i] = pb.contacts[i + 1];
        i++;
    }
    return (pb);
}

void PhoneBook::display(PhoneBook pb)
{
    int i;
    int max;
    std::string index;

    i = 0;
    if (pb.contacts[0].isnull(pb.contacts[0]))
    {
        std::cout << "Your Phonebook is empty!!\n";
        return;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    while (i < 8)
    {
        if (pb.contacts[i].isnull(pb.contacts[i]))
            break;
        std::cout << "|" << std::setw(10) << i << "|";
        contacts[i].print_info(contacts[i], 1);
        std::cout << "|";
        contacts[i].print_info(contacts[i], 2);
        std::cout << "|";
        contacts[i].print_info(contacts[i], 3);
        std::cout << "|\n";
        std::cout << "|-------------------------------------------|" << std::endl;
        i++;
    }
}