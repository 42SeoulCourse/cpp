#include "easyfind.hpp"

int main() {
    std::cout << "/************ Vector test ************/" << std::endl;
    std::vector<int> vector;

    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);

    try {
      std::vector<int>::iterator value = easyfind(vector, 1);
      std::cout << "The Value is " << *value << std::endl;
      value = easyfind(vector, 5);
      std::cout << "The Value is " << *value << std::endl;
    } catch (const std::exception& e) {
      std::cout << "🌈error🌈 Value does not exist in vector" << std::endl;
    }

    std::cout << std::endl;
    
    std::cout << "/************ List test ************/" << std::endl;
    std::list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    try {
      std::list<int>::iterator value = easyfind(list, 1);
      std::cout << "The Value is " << *value << std::endl;
      value = easyfind(list, 5);
      std::cout << "The Value is " << *value << std::endl;
    } catch (const std::exception& e) {
      std::cout << "🌈error🌈 Value does not exist in list" << std::endl;
    }
}