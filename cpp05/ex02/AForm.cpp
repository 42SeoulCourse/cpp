#include "./AForm.hpp"

AForm::AForm(void)
    : _name("Default"),
      _grade_to_sign(LOWEST_GRADE),
      _grade_to_execute(LOWEST_GRADE),
      _is_signed(false) {
  // std::cout << "AForm created. Default." << std::endl;
  return;
}

AForm::AForm(const std::string name, const int grade_to_sign,
           const int grade_to_execute)
    : _name(name),
      _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute),
      _is_signed(false) {
  if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE) {
    throw(AForm::GradeTooHighException());
  }
  if (grade_to_execute > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE) {
    throw(AForm::GradeTooLowException());
  }
  // 초기화 리스트가 맞는지, 여기서 하는게 맞는지..? grade = this->_grade;
}

// 초기화 리스트??
AForm::AForm(const AForm &src)
    : _name(src.getName()),
      _grade_to_sign(src.getGradeToSign()),
      _grade_to_execute(src.getGradeToExecute()),
      _is_signed(src.getIsSigned()) {
  // std::cout << "Copy constructor called. " << std::endl;
}

AForm::~AForm(void) {
  // std::cout << "AForm destroyed." << std::endl;
  return;
}

AForm &AForm::operator=(const AForm &rhs) {
  if (this != &rhs) {
    std::cout << "Copy Assignment operator can't copy Const value(name, grades)"
              << std::endl;
    this->_is_signed = rhs._is_signed;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs) {
  o << "AForm name : " << rhs.getName() << ". Signed : " << rhs.getIsSigned()
    << ". Grade needed to sign : " << rhs.getGradeToSign()
    << ". Grade needed to execute : " << rhs.getGradeToExecute() << std::endl;
  return (o);
}

std::string AForm::getName() const { return this->_name; };

bool AForm::getIsSigned() const { return this->_is_signed; };

int AForm::getGradeToSign() const { return this->_grade_to_sign; };

int AForm::getGradeToExecute() const { return this->_grade_to_execute; };

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() <= this->getGradeToSign()) {
    this->_is_signed = true;
    return;
  }
  throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return ("❗️Form exception❗️ Grade is too High !!");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("❗️Form exception❗️ Grade is too Low !!");
}

const char *AForm::InvalidSignCondition::what() const throw() {
  return ("❗️Form exception❗️ Form is not signed !!");
}
