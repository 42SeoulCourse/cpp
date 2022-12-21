#include "Harl.hpp"

Harl::Harl(void) { std::cout << "Harl created.  Default." << std::endl; }

Harl::~Harl(void) { std::cout << "Harl destroyed." << std::endl; }

void Harl::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"
      << std::endl
      << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl
      << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << std::endl
      << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl
            << std::endl;
}

void Harl::complain(std::string level) {
  std::string _level[4] = {
      "DEBUG",
      "INFO",
      "WARNING",
      "ERROR",
  };

  void (Harl::*function[4])(void) = {
      &Harl::debug,
      &Harl::info,
      &Harl::warning,
      &Harl::error,
  };

  for (int index = 0; index < 4; index++) {
    if (_level[index] == level) {
      (this->*function[index])();
      return;
    }
  }
  return;
}

void Harl::complainFilter(std::string level) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int         index = 0;
  
  while (index < 4) {
    if (!level.compare(levels[index])) {
      break;
    }
    index++;
  }

  switch (index) {
    case 0:
      Harl::complain("DEBUG");
    case 1:
      Harl::complain("INFO");
    case 2:
      Harl::complain("WARNING");
    case 3:
      Harl::complain("ERROR");
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
  }
  return;
}
