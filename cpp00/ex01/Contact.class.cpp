#include <string>
#include <iostream>

class phonebook
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
    public:
        phonebook( void );
        phonebook(
                std::string first_name,
                std::string last_name,
                std::string nickname,
                std::string phone_number );
        ~phonebook();

        std::string     getFirstName( void );
        void            print_info( void );
};

phonebook::phonebook( void )
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

phonebook::phonebook(
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

std::string phonebook::getFirstName( void )
{
    return ( this->first_name );
}

void        phonebook::print_info( )
{
    std::cout << this->first_name << std::endl;
    std::cout << this->last_name << std::endl;
    std::cout << this->nickname << std::endl;
    std::cout << this->phone_number << std::endl;

}

phonebook::~phonebook( )
{
    std::cout << "Finsh" << std::endl;
}