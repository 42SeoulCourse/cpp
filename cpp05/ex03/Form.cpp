#include "./Form.hpp"

Form::Form(void)
    : _name("Default"),
      _grade_to_sign(LOWEST_GRADE),
      _grade_to_execute(LOWEST_GRADE),
      _is_signed(false) {
  // std::cout << "Form created. Default." << std::endl;
  return;
}

Form::Form(const std::string name, const int grade_to_sign,
           const int grade_to_execute)
    : _name(name),
      _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute),
      _is_signed(false) {
  if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE) {
    throw(Form::GradeTooHighException());
  }
  if (grade_to_execute > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE) {
    throw(Form::GradeTooLowException());
  }
  // 초기화 리스트가 맞는지, 여기서 하는게 맞는지..? grade = this->_grade;
}

// 초기화 리스트??
Form::Form(const Form &src)
    : _name(src.getName()),
      _grade_to_sign(src.getGradeToSign()),
      _grade_to_execute(src.getGradeToExecute()),
      _is_signed(src.getIsSigned()) {
  // std::cout << "Copy constructor called. " << std::endl;
}

Form::~Form(void) {
  // std::cout << "Form destroyed." << std::endl;
  return;
}

Form &Form::operator=(const Form &rhs) {
  if (this != &rhs) {
    std::cout << "Copy Assignment operator can't copy Const value(name, grades)"
              << std::endl;
    this->_is_signed = rhs._is_signed;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs) {
  o << "Form name : " << rhs.getName() << ". Signed : " << rhs.getIsSigned()
    << ". Grade needed to sign : " << rhs.getGradeToSign()
    << ". Grade needed to execute : " << rhs.getGradeToExecute() << std::endl;
  return (o);
}

const std::string Form::getName() const { return this->_name; };

bool Form::getIsSigned() const { return this->_is_signed; };

int Form::getGradeToSign() const { return this->_grade_to_sign; };

int Form::getGradeToExecute() const { return this->_grade_to_execute; };

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() <= this->getGradeToSign()) {
    this->_is_signed = true;
    return;
  }
  throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("❗️Form exception❗️ Grade is too High !!");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("❗️Form exception❗️ Grade is too Low !!");
}

const char *Form::InvalidSignCondition::what() const throw() {
  return ("❗️Form exception❗️ Form is not signed !!");
}
