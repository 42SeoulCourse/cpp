#include <string>
#include <iostream>

class Character {
    public:
     virtual void sayHello(std::string const &target);
};

class Warrior : public Character {
     public:
      virtual void sayHello(std::string const &target);
};

class Cat
{
    //[...]
};

void    Character::sayHello(std::string const &target) {
      std::cout << "Hello " << target << " !" << std::endl;
}

void    Warrior::sayHello(std::string const &target)
{
      std::cout << "F*** off" << target << ", I don't like you !" << std::endl;
}

int main(void) {
    // 워리어는 워리어 클래스를 생성하기 때문에 작동한다.
    Warrior *a = new Warrior();

    // 캐릭터는 워리어클래스의 부모이기 때문에 작동한다.
    Character *b = new Warrior();

    // 캐릭터는 워리어 클래스의 상속을 받지 않기 떄문에 작동안한다.
    // Warrior *c = new Character();

    // 캐릭터는 고양이 클래스의 상속을 받지 않기 때문에 작도 안한다.
    // Character *d = new Cat();

    a->sayHello("students");
    b->sayHello("students");
}