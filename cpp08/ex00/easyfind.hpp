#ifndef EASYFINE_HPP
#define EASYFINE_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container, const int n) {
  typename T::iterator value = std::find(container.begin(), container.end(), n);
  if (value == container.end()) {
    throw std::exception();
  }
  return value;
}

#endif