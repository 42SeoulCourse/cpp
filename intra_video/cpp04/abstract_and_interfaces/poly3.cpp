#include <string>
#include <iostream>

class ACharacter {
    public:
     virtual void attack(std::string const &target) = 0;
     void         sayHello(std::string const &target);
};

class Warrior : public ACharacter {
    public:
     virtual void attack(std::string const &target);
};

void    ACharacter::sayHello(std::string const &target) {
     std::cout << "Hello" << target << " !" << std::endl;
}

void    Warrior::attack(std::string const &target) {
     std::cout << "attacks " << target << " with a sword" << std::endl;
}

// class ICoffeeMaker {
//     public:
//      virtual void fillWaterTank(IWaterSource *src) = 0;
//      virtual ICoffee* makeCoffee(IWaterSource *src) = 0;
// };

int main() {
    ACharacter* a = new Warrior();

    a->sayHello("students");
    a->attack("roger");
}