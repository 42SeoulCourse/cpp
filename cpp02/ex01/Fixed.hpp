#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
 private:
  int              _n;
  static const int _fractional = 8;

 public:
  Fixed(void);
  Fixed(const int n);
  Fixed(const float n);
  Fixed(const Fixed &fixed);

  ~Fixed(void);

  Fixed &operator=(const Fixed &fixed);

  int   getRawBits(void) const;
  void  setRawBits(int const raw);
  int  toInt(void) const;
  float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif