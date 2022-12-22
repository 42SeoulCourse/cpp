#include <iostream>

class Cat
{
    private:
     int _numberOfLegs;

    public:
     Cat();
     Cat(Cat const &);
     Cat &operator=(const Cat &);
     ~Cat();

     void run(int distance);

     void scornSameone(const std::string &target);
};

class Pony
{
    private:
     int _numberOfLegs;

    public:
     Pony(void);
     Pony(const Pony &src);
     virtual ~Pony(void);
     Pony &operator=(const Pony &rhs);

     void run(int distance);

     void doMagic(const std::string &target);
};
