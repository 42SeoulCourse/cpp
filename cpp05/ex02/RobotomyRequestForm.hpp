#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <sys/time.h>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string      _target;
  static const int RR_GRADE_TO_SIGN = 72;
  static const int RR_GRADE_TO_EXEC = 45;
  
 public:
  RobotomyRequestForm(void);
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& src);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
  virtual ~RobotomyRequestForm(void);

  const std::string& getTarget() const;
  void               execute(Bureaucrat const& executor) const;
};

#endif