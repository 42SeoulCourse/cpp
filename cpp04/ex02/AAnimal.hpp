#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal(void);
        AAnimal(std::string type);
        AAnimal(const AAnimal& src);
        AAnimal& operator=(AAnimal const& rhs);
        virtual ~AAnimal(void);

        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
};

#endif