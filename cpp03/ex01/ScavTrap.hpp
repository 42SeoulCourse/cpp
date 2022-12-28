#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    private:

    protected:

    public:
     ScavTrap(void);
     ScavTrap(std::string name);
     ScavTrap(const ScavTrap &src);
     ScavTrap &operator=(const ScavTrap &rhs);
     ~ScavTrap(void);

     void guardGate();
     void attack(const std::string &target);
};

std::ostream &operator<<(std::ostream &o, const ScavTrap &scavtrap);

#endif
