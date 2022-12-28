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
