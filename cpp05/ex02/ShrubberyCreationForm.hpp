#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "./AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;
  static const int  SC_GRADE_TO_SIGN = 145;
  static const int  SC_GRADE_TO_EXEC = 137;

 public:
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm& src);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const& rhs);
  virtual ~ShrubberyCreationForm(void);

  void               execute(Bureaucrat const& executor) const;
  const std::string &getTarget() const;

  class FileIOException : public std::exception {
    virtual const char* what() const throw();
  };
};

#endif