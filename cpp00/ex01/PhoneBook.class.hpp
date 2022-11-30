#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <string>
# include "Contact.class.hpp"

class PhoneBook
{
    public:
    
        PhoneBook( void );
        ~PhoneBook( void );

        int          check_pb(PhoneBook pb);
        void         display(PhoneBook pb);
        PhoneBook    del_one(PhoneBook pb);
        PhoneBook    add_i(PhoneBook pb, int i);

    private:
        Contact contacts[9];
};

#endif