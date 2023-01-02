#ifndef AFORM_HPP
# define AFORM_HPP

# include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  const std::string _name;
  const int         _grade_to_sign;
  const int         _grade_to_execute;
  bool              _is_signed;

 public:
  AForm(void);
  AForm(const std::string name, const int grade_to_sign,
       const int grade_to_execute);
  AForm(const AForm& src);
  AForm& operator=(AForm const& rhs);
  virtual ~AForm(void);

  const std::string getName() const;
  bool        getIsSigned() const;
  int         getGradeToSign() const;
  int         getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
    virtual const char* what() const throw();
  };

  class InvalidSignCondition : public std::exception {
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& o, AForm const& form);

#endif
