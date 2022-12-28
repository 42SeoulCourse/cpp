#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
  std::cout << "Bureaucrat created. Default." << std::endl;
  return;
}

Bureaucrat::Bureaucrat(std::string const name, int grade)
    : _name(name), _grade(grade) {
  if (grade < HIGHEST_GRADE) {
    throw(Bureaucrat::GradeTooHighException());
  }
  if (grade > LOWEST_GRADE) {
    throw(Bureaucrat::GradeTooLowException());
  }
// 초기화 리스트가 맞는지, 여기서 하는게 맞는지..? grade = this->_grade;
}

// 초기화 리스트??
Bureaucrat::Bureaucrat(const Bureaucrat &src) {
  std::cout << "Copy constructor called. " << std::endl;
  *this = src;
}

Bureaucrat::~Bureaucrat(void) {
  std::cout << "Bureaucrat destroyed." << std::endl;
  return;
}

const std::string Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this != &rhs) {
    std::cout << "Copy Assignment operator can't copy Const value(name)"
              << std::endl;
    this->_grade = rhs._grade;
  }
  return *this;
}

void Bureaucrat::incrementGrade(void) {
  if (this->_grade == HIGHEST_GRADE) {
    throw(Bureaucrat::GradeTooHighException());
  }
  --(this->_grade);
};

void Bureaucrat::decrementGrade(void) {
  if (this->_grade == LOWEST_GRADE) {
    throw(Bureaucrat::GradeTooLowException());
  }
  ++(this->_grade);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs) {
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
  return (o);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("❗️Bureaucrat exception❗️ Grade is over the Max !!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("❗️Bureaucrat exception❗️ Grade is under the Minimum !!");
}

// void  Bureaucrat::signForm(const Form &form) const {
//   if ()
//   {
//     /* code */
//   }
  
// //             <bureaucrat> signed <form>

// //             아니면

// //             <bureaucrat> couldn’t sign <form> because <reason>

// }