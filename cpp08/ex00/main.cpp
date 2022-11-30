#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include "easyfind.hpp"

template<typename T>
void    do_test(T &container, int number)
{
    typename T::iterator    it = easyfind(container, number);

    if ( it == container.end() )
        std::cout << "No " << number << " in the container" << std::endl;
    else
        std::cout << "Found " << number << " on the index of " << std::distance( container.begin(), it ) << std::endl;
}

int main(void)
{
    std::cout << "--- A LIST ---" << std::endl;
    std::list<int> lst;

    for (int index = 0; index < 100; ++index)
        lst.push_back(index * 2);
    
    do_test(lst, 16);
    do_test(lst, 32);
    do_test(lst, 65);

    std::cout << std::endl << "--- A VECTOR ---" << std::endl;
    std::vector<int> vector;

    for (int index = 0; index < 100; ++index)
        vector.push_back(index * 2);

    do_test(lst, 16);
    do_test(lst, 32);
    do_test(lst, 65);

    std::cout << std::endl << "--- A SET ---" << std::endl;
    int ints[] = { 1, 2, 65 };
    std::set<int> set(ints, ints + sizeof(ints) / sizeof(int));

    do_test(set, 16);
    do_test(set, 32);
    do_test(set, 65);
}