#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : Form("PP", RR_GRADE_TO_SIGN, RR_GRADE_TO_EXEC), _target("Default") {
  // std::cout << "PresidentialPardonForm created. Default." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("PP", RR_GRADE_TO_SIGN, RR_GRADE_TO_EXEC), _target(target) {
  // std::cout << "PresidentialPardonForm created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& src)
    : _target(src.getTarget()) {
  // std::cout << "Copy constructor called. " << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
  // std::cout << "PresidentialPardonForm destroyed." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& rhs) {
  if (this != &rhs) {
    _target = rhs._target;
  }
  return *this;
}

const std::string& PresidentialPardonForm::getTarget() const { return _target; }

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (!this->getIsSigned()) {
    throw Form::InvalidSignCondition();
  }
  if (executor.getGrade() > this->getGradeToExecute()){
		throw Form::GradeTooLowException();
  }
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
