#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>

class Conversion {
 private:
  std::string _input;
  int         _i;
  float       _f;
  char        _c;
  double      _d;

  static const int CHAR_TYPE = 1;
  static const int FLOAT_TYPE = 2;
  static const int DOUBLE_TYPE = 3;
  static const int INT_TYPE = 4;
  static const int PSEUDO = 5;
  static const int INVALID = 6;

  int  _type;
  bool _isWrong;

 public:
  Conversion(void);
  // Conversion(const std::string input);
  Conversion(const Conversion &src);
  Conversion& operator=(Conversion const &rhs);
  virtual ~Conversion(void);

  void detectType(char *input);

	void convertData();
	void printData() const;
	void getInt() const;
	void getFloat() const;
	void getChar() const;
	void getDouble() const;
	int  getType() const;

	void setType(int type);
  const std::string &getInput() const;

	void setInput(const std::string &input);
  bool isPseudo(std::string str);
};

std::ostream& operator<<(std::ostream &o, Conversion const &rhs);
std::string   convertLiteralToDouble(std::string input);

#endif
