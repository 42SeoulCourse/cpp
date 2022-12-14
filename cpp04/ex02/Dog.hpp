#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
    private:
     Brain *brain;

    public:
     Dog(void);
     Dog(const Dog &src);
     Dog &operator=(const Dog &rhs);
     virtual ~Dog(void);

     void makeSound(void) const;
     Brain *getBrain(void) const;
};

#endif