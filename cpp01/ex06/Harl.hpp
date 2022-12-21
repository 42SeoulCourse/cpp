#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
 private:
  void debug(void);
  void info(void);
  void error(void);
  void warning(void);

 public:
  Harl(void);
  ~Harl(void);

  void complain(std::string level);
  void complainFilter(std::string level);
};

#endif