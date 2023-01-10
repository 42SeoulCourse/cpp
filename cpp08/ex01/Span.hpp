#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <set>
# include <vector>

class Span {
 private:
  std::multiset<int> _set;
  unsigned int       _n;

 public:
  Span(void);
  Span(unsigned int n);
  Span(Span const &src);
  Span &operator=(const Span &rhs);
  ~Span(void);

  void         addNumber(const int n);
  void         addNumber(std::vector<int>::iterator start,
                         std::vector<int>::iterator end);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  void         printAll();
};

#endif