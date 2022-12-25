#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "./ClapTrap.hpp"

class FragTrap : public ClapTrap {
    private:

    protected:

    public:
     FragTrap(void);
     FragTrap(std::string name);
     FragTrap(const FragTrap &src);
     FragTrap &operator=(const FragTrap &rhs);
     ~FragTrap(void);

     void highFivesGuys(void);
     void attack(const std::string &target);
};

std::ostream &operator<<(std::ostream &o, const FragTrap &flagtrap);

#endif

// - ClapTraps 를 상속 받아서 FragTrap 클래스를 만들자
// - ClapTrap 의 생성자와 소멸자를 상속받지만, FragTrap 의 생성자 소멸자 attack() 은 다른 메세지를 출력한다. ClapTrap 등른 자신의 개성을 안다.
// - 생성자와 소멸자의 체이닝(?)이 너의 테스트에 보여야한다. FragTrap 이 생성되면, 프로그램은 ClapTrap을 생성하며 시작된다. 소멸자는 반대 순서다.
// - FragTrap 은 ClapTrap 의 속성을 사용할 것이다.
//     - Name
//     - Hit points(100)
//     - Energy points(50)
//     - Attack damage(20)
// - ScavTrap은 자신만의 멤버 함수를 갖는다.
//       FragTrap 이 Gatekeeper mode 라는 것을 알리는 메세지를 출력하는 멤버 함수이다