#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>

# define CHAR_TYPE 0;
# define INT_TYPE 1;
# define FLOAT_TYPE 2;
# define DOUBLE_TYPE 3;
# define PSEUDO 4;
# define WRONG_TYPE 5;

class Conversion {
 private:
  std::string _input;
  char        _c;
  int         _i;
  float       _f;
  double      _d;

  std::string _char;
  std::string _int;
  std::string _float;
  std::string _double;



 public:
  Conversion(void);
  Conversion(const std::string input);
  Conversion(const Conversion &src);
  Conversion& operator=(Conversion const &rhs);
  virtual ~Conversion(void);

  void convert();
  void displayChar() const;
  void displayInt() const;
  void displayFloat() const;
  void displayDouble() const;

  const int getType();
  const bool      isPseudo(std::string input);
};

std::ostream& operator<<(std::ostream &o, Conversion const &rhs);

#endif