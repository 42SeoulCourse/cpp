#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
 private:
  int              _integer;
  static const int _fractional = 8;

 public:
  Fixed(void);
  ~Fixed(void);
  Fixed(Fixed &fixed);
  Fixed &operator=(Fixed &fixed);

  int  getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif