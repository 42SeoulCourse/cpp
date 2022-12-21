#include <iostream>
#include "Integer.class.hpp"

int main(void) {
    Integer x(30);
    Integer y(10);
    Integer z(0);

    std::cout << "Value of x : " << x << std::endl;
    std::cout << "Value of y : " << y << std::endl;
// 같은 메모리 주소를 가진 복사 생성자를 생성해서 값을 바꾼 후에 소멸
    y = Integer(12);
    std::cout << "Value of y : " << y << std::endl;

    std::cout << "Value of z : " << z <<  std::endl;
    z = x + y;
    std::cout << "Value of z : " << z << std::endl;

    return 0;
}