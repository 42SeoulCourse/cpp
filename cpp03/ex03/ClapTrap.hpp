#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
 protected:
  std::string  _name;
  unsigned int _hit_points;
  unsigned int _energy_points;
  unsigned int _attack_damage;

 public:
  ClapTrap(void);
  ClapTrap(const std::string name);
  ClapTrap(const ClapTrap &src);
  ClapTrap &operator=(const ClapTrap &rhs);
  ~ClapTrap(void);

  ClapTrap(std::string name, unsigned int _hit_points,
           unsigned int _energy_points, unsigned int _attack_damage);

  const std::string  getName(void) const;
  unsigned int       getHitPoints(void) const;
  unsigned int       getEnergyPoints(void) const;
  unsigned int       getAttackDamage(void) const;
  void               attack(const std::string &target);
  void               takeDamage(unsigned int amount);
  void               beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &o, const ClapTrap &claptrap);

#endif
