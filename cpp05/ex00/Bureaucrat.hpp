#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include <iostream>
# include <string>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat {
 private:
  const std::string _name;
  int               _grade;

 public:
  Bureaucrat(void);
  Bureaucrat(std::string const name, int grade);
  Bureaucrat(const Bureaucrat &src);
  Bureaucrat &operator=(Bureaucrat const &rhs);
  virtual ~Bureaucrat(void);

  const std::string getName(void) const;
  int               getGrade(void) const;

  void incrementGrade(void);
  void decrementGrade(void);

  // 예를 바깥에 선언하면 어떻게 됨??
  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };
  
  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif

// - Bureaucrat
//     - const name
//     - 1(highest) ~ 150(lowest) grade

//         유효한 grade 가 아니면 예외를 던진다.

//         - Bureaucrat::GradeTooHighException
//         - Bureaucrat::GradeTooLowException
// - getName() 과 getGrade()
// - grade를 증가하고 감소하기 위한 2개의 멤버 함수
//     - grade 가 범위를 벋어나면 예외 던짐
// - 증가는 3 → 2 이다.
// - try catch 를 이용해라
// - << 연산자 오버로딩을 통해 출력해라

//     ex. <name>, bureaucrat grade <grade>