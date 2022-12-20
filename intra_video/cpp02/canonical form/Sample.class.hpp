#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

# include <iostream>

class Sample {
 private:
  int _foo;

 public:
  Sample(void);  // Canonical form 생성자
  Sample(int const n);
  Sample(Sample const& src);  // Canonical form 복사 생성자
  ~Sample(void);              // Canonical form 소멸자

  Sample& operator=(Sample const& rhs);  // Canonical form 대입 연산자 오버로딩

  int getFoo(void) const;
};

std::ostream& operator<<(std::ostream& o, Sample const& i);

#endif