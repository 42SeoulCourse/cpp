#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  const int         _grade_to_sign;
  const int         _grade_to_execute;
  bool              _is_signed;

 public:
  Form(void);
  Form(const std::string name, const int grade_to_sign,
       const int grade_to_execute);
  Form(const Form& src);
  virtual ~Form(void);
  Form& operator=(Form const& rhs);

  std::string getName() const;
  bool        getIsSigned() const;
  int         getGradeToSign() const;
  int         getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& o, Form const& form);

#endif
