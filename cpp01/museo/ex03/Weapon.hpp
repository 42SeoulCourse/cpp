#ifndef Weapon_HPP
# define Weapon_HPP

# include <iostream>

class Weapon {
 private:
  std::string _type;

 public:
  Weapon(void);
  ~Weapon(void);

  Weapon(std::string type);

  std::string& getType(void);
  void setType(std::string type);
};

#endif