#ifndef Weapon_HPP
# define Weapon_HPP

# include <iostream>

class Weapon {
 private:
  std::string _type;

 public:
  Weapon(void);
  ~Weapon(void);

  Weapon(const std::string type);
  Weapon(void *a);

  const std::string& getType(void) const;
  void setType(std::string type);
};

#endif