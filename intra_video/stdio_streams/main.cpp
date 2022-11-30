#include <iostream>

int main(void) {
    char buff[512];

    std::cout << "hello world !" << std::endl;

    std::cout << "Input a world: ";
    std::cin >> buff;
    std::cout << "You entered: [" << buff << "]" << std::endl;
    return 0;
}