#include "./Form.hpp"

Form::Form(void) : _name("Default"), _grade(150) {
  std::cout << "Form created. Default." << std::endl;
  return;
}

Form::Form(std::string const name, int grade)
    : _name(name), _grade(grade) {
  if (grade < HIGHEST_GRADE) {
    throw(Form::GradeTooHighException());
  }
  if (grade > LOWEST_GRADE) {
    throw(Form::GradeTooLowException());
  }
// 초기화 리스트가 맞는지, 여기서 하는게 맞는지..? grade = this->_grade;
}

// 초기화 리스트??
Form::Form(const Form &src) {
  std::cout << "Copy constructor called. " << std::endl;
  *this = src;
}

Form::~Form(void) {
  std::cout << "Form destroyed." << std::endl;
  return;
}

const std::string Form::getName(void) const { return (this->_name); }

int Form::getGrade(void) const { return (this->_grade); }

Form &Form::operator=(const Form &rhs) {
  if (this != &rhs) {
    std::cout << "Copy Assignment operator can't copy Const value(name)"
              << std::endl;
    this->_grade = rhs._grade;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs) {
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
  return (o);
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("❗️Bureaucrat exception❗️ Grade is over the Max !!");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("❗️Bureaucrat exception❗️ Grade is under the Minimum !!");
}
