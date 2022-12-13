#include <iostream>
#include <string>

// void    byPtr(std::string *str)
// {
//     *str += " and ponies";
// }

// // 값을 바꾸는게 아니기 때문에 const 매개변수로 받는다.
// void    byConstPtr(std::string const *str)
// {
//     std::cout << *str << std::endl;
// }

void    byRef(std::string &str)
{
    str += " and ponies";
}

// 값을 바꾸는게 아니기 때문에 const 매개변수로 받는다.
void    byConstRef(std::string const &str)
{
    std::cout << str << std::endl;
}

int main(void)
{
    // std::string str = "i like butterflies";

    // std::cout << str << std::endl;
    // byPtr(&str);
    // byConstPtr(&str);

    std::string str = "i like otters";

    std::cout << str << std::endl;
    byRef(str);
    byConstRef(str);

    return (0);
}