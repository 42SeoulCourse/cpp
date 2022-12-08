#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
    public:
        Contact( void );
        ~Contact( void );

        Contact(
            std::string first_name,
            std::string last_name,
            std::string nickname,
            std::string phone,
            std::string secret
        );

        Contact add(Contact contact);
        int     isnull(Contact contact);
        void    display_entire_info(Contact contact);
        void    print_info(Contact contact, int i);
        static int count;
    
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone;
        std::string _secret;
};

#endif