#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
    return ;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

PhoneBook::PhoneBook( void )
{
    std::cout << "Enter your first name: ";
    std::cin >> this->first_name;
    std::cout << "Enter your last name: ";
    std::cin >> this->last_name;
    std::cout << "Enter your nick name: ";
    std::cin >> this->nickname;
    std::cout << "Enter your phone_number: ";
    std::cin >> this->phone_number;
}

PhoneBook::PhoneBook(
                std::string first_name,
                std::string last_name,
                std::string nickname,
                std::string phone_number )
{
    std::cout << "New Entry!!" << std::endl;
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
}

std::string PhoneBook::getFirstName( void )
{
    return ( this->first_name );
}

void        PhoneBook::print_info( )
{
    std::cout << this->first_name << std::endl;
    std::cout << this->last_name << std::endl;
    std::cout << this->nickname << std::endl;
    std::cout << this->phone_number << std::endl;

}

PhoneBook::~PhoneBook( )
{
    std::cout << "Finsh" << std::endl;
}