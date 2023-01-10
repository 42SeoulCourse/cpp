#include <algorithm>
#include <iostream>
#include <list>

void displayInt(int i) { std::cout << i << std::endl; }

int main() {
  std::list<int> lst;

  lst.push_back(10);
  lst.push_back(11);
  lst.push_back(12);
  lst.push_back(13);
  lst.push_back(1100);

  std::for_each(lst.begin(), lst.end(), displayInt);
  return (0);
}