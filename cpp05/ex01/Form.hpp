#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"

class Form {
 private:
  const std::string _name;
  const int         grade_to_sign;
  const int         grade_to_execute;
  bool              is_signed;

 public:
  Form(void);
  Form(const Form &src);
  virtual ~Form(void);
  Form& operator=(Form const& rhs);

  const std::string getName() const;
  bool getIsSigned() const;
  const int getGradeToSign() const;
  const int getGradeToExecute() const;

  void beSigned(Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
    virtual const char* what() const throw();
  };
};

#endif

// - Form class 만들기
//     - private
//         - const name
//         - 서명 여부 boolean (초기값은 0)
//         - 서명을 요구하는 const grade
//         - 실행을 요구하는 const grade
//     - Form::GradeTooHighException
//     - Form::GradeTooLowException
//     - beSigned(Bureaucrat) 멤버 함수
//         - 등급이 충분히 높으면 양식 상태를 서명됨으로 변경합니다.(필요한
//         것보다 높거나 같음).
//     - SignForm(Bureaucrat) 멤버함수
//         - form에 사인되면 다음을 출력

//             <bureaucrat> signed <form>

//             아니면

//             <bureaucrat> couldn’t sign <form> because <reason>

// - 모든 속성에 대한 getter
// - 모든 form 정보를 출력하는 << 연산자 오버로딩