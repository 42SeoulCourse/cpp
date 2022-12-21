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
  Fixed(const float f);
  Fixed(const Fixed &fixed);

  ~Fixed(void);


  int   getRawBits(void) const;
  void  setRawBits(const int raw);

  int   toInt(void) const;
  float toFloat(void) const;

  Fixed  &operator=(const Fixed &fixed);

  Fixed  operator+(const Fixed &fixed) const;
  Fixed  operator-(const Fixed &fixed) const;
  Fixed  operator*(const Fixed &fixed) const;
  Fixed  operator/(const Fixed &fixed) const;
  
  // 후위증감연산자
  Fixed  operator++(int);
  Fixed  operator--(int);
  // 전위증감연산자
  Fixed  &operator++(void);
  Fixed  &operator--(void);

  bool operator>(const Fixed &fixed) const;
  bool operator<(const Fixed &fixed) const;
  bool operator>=(const Fixed &fixed) const;
  bool operator<=(const Fixed &fixed) const;
  bool operator==(const Fixed &fixed) const;
  bool operator!=(const Fixed &fixed) const;

  // static 과 const 를 같이 사용할 수 없는 이유...
  // const 함수는 자신의 함수에서 해당 객체를 바꾸지 말라는 의미이다.
  // 근데 static 함수는 클래스 안에서 생성하지만, 특정 객체에 구속되지 않기 때문에,
  // const와 static 을 같이 사용하라는 말은 말이 안된다.
  // static 을 멤버함수로 사용하는 이유는 다른 클래스나 클래스 외부에 같은 이름의 함수가 잇을 수 있기때문이다.
  static const Fixed        &max(const Fixed &fixed1, const Fixed &fixed2);
  static const Fixed        &min(const Fixed &fixed1, const Fixed &fixed2);
  static Fixed        &max(Fixed &fixed1, Fixed &fixed2);
  static Fixed        &min(Fixed &fixed1, Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif
