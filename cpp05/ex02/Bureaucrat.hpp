#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include <iostream>
# include <string>
# include "./AForm.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class AForm;

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

  void signForm(AForm &aform) const;
  void incrementGrade(void);
  void decrementGrade(void);
  void executeForm(AForm const &aform) const;

  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };
  
  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif
