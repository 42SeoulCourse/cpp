#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RR", RR_GRADE_TO_SIGN, RR_GRADE_TO_EXEC), _target("Default") {
  // std::cout << "RobotomyRequestForm created. Default." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RR", RR_GRADE_TO_SIGN, RR_GRADE_TO_EXEC), _target(target) {
  // std::cout << "RobotomyRequestForm created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : _target(src.getTarget()) {
  // std::cout << "Copy constructor called. " << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
  // std::cout << "RobotomyRequestForm destroyed." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& rhs) {
  if (this != &rhs) {
    _target = rhs._target;
  }
  return *this;
}

const std::string& RobotomyRequestForm::getTarget() const { return _target; }

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (!this->getIsSigned()) {
    throw AForm::InvalidSignCondition();
  }
  if (executor.getGrade() > this->getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }
  std::cout << "drilllgggg........driigggg...." << std::endl;
  srand(time(NULL));
  int random = rand();
  if (random % 2 == 0) {
    std::cout << _target << " has been robotomized" << std::endl;
  } else {
    std::cout << _target << " has been failed to robotomized." << std::endl;
  }
}
