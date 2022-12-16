#include <iostream>

int main(void) {
  std::string string = "HI THIS IS BRAIN";
  std::string *stringPTR = &string;
  std::string &stringREF = string;

  std::cout << "Memory address - string variable: " << &string << std::endl;
  std::cout << "Memory address - stringPTR: " << stringPTR << std::endl;
  std::cout << "Memory address - stringREF" << &stringREF << std::endl;
  std::cout << "--------------------------------" << std::endl;
  std::cout << "Value - string variable: " << stringREF << std::endl;
  std::cout << "Value - stringPTR: " << *stringPTR << std::endl;
  std::cout << "Value - stringREF: " << stringREF << std::endl;
}