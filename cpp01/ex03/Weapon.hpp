#ifndef Weapon_HPP
# define Weapon_HPP

# include <iostream>

class Weapon {
 private:
  std::string const _type;

 public:
  Weapon(void);
  ~Weapon(void);

  Weapon(std::string type);

  const std::string& getType(void) const;
  void setType(std::string type);
};

#endif