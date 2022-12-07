#include "Contact.class.hpp"

Contact::Contact(
    std::string first_name,
    std::string last_name,
    std::string nickname,
    std::string phone,
    std::string secret) :
    _first_name(first_name),
    _last_name(last_name),
    _nickname(nickname),
    _phone(phone),
    _secret(secret) {
        return ;
}

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}

int     Contact::isnull(Contact contact)
{
    if (contact._first_name.empty())
        return (1);
    return (0);
}

void    Contact::print_info(Contact contact, int i)
{
    if (i == 1)
    {
        if (contact._first_name.size() > 10)
            std::cout << std::string(contact._first_name.begin(), contact._first_name.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << contact._first_name;
    }
    if (i == 2)
    {
        if (contact._last_name.size() > 10)
            std::cout << std::string(contact._last_name.begin(), contact._last_name.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << contact._last_name;
    }
    if (i == 3)
    {
        if (contact._nickname.size() > 10)
            std::cout << std::string(contact._nickname.begin(), contact._nickname.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << contact._nickname;
    }
}

void    Contact::display_entire_info(Contact contact)
{
    std::cout << "First name: " << contact._first_name << std::endl;
    std::cout << "Last name: " << contact._last_name << std::endl;
    std::cout << "Nickname: " << contact._nickname << std::endl;
    std::cout << "Phone number: " << contact._phone << std::endl;
    std::cout << "Darkest secret: " << contact._secret << std::endl;
}