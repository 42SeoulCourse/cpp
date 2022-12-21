#include <iostream>
#include "Sample.class.hpp"

int main() {
    Sample instance1(42);
    Sample instance2(42);

    if (&instance1 == &instance1)
        std::cout << "1 and 1 are physically equal" << std::endl;
    else
        std::cout << "1 and 1 are not physically equal" << std::endl;
    
    if (&instance1 == &instance2)
        std::cout << "1 and 2 are physically equal" << std::endl;
    else
        std::cout << "1 and 2 are not physically equal" << std::endl;
    
    if (instance1.compare(&instance1) == 0)
        std::cout << "1 and 1 are structually equal" << std::endl;
    else
        std::cout << "1 and 1 are not structually equal" << std::endl;

    if (instance1.compare(&instance2) == 0)
        std::cout << "1 and 2 are structually equal" << std::endl;
    else
        std::cout << "1 and 2 are not structually equal" << std::endl;
    return 0;
}