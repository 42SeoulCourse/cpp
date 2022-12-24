#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {
 private:
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

  // target name 을 읽어와야함...
  const std::string &getName(void) const;
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

// target name 을 읽어와야하기 때문에 << 연산자 오버로딩이 필요하다.
std::ostream &operator<<(std::ostream &o, const ClapTrap &claptrap);

#endif
