#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("SC", SC_GRADE_TO_SIGN, SC_GRADE_TO_EXEC), _target("Default") {
  // std::cout << "ShrubberyCreationForm created. Default." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("SC", SC_GRADE_TO_SIGN, SC_GRADE_TO_EXEC), _target(target) {
  // std::cout << "ShrubberyCreationForm created. Default." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : _target(src.getTarget()) {
  // std::cout << "Copy constructor called. " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  // std::cout << "ShrubberyCreationForm destroyed." << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const { return _target; }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& rhs) {
  if (this != &rhs) {
    this->_target = rhs._target;
  }
  return *this;
}

const char *ShrubberyCreationForm::FileIOException::what() const throw() {
  return ("❗️IOS exception❗️ Error occurs !!!!");
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (!this->getIsSigned()) {
    throw AForm::InvalidSignCondition();
  }
  if (executor.getGrade() > this->getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }
  std::ifstream ifs("ASCII.txt");
  if (!ifs.good()) {
    throw ShrubberyCreationForm::FileIOException();
  }
  std::ofstream ofs(std::string(this->_target) + "_shrubbery");
  if (!ofs.good()) {
    throw ShrubberyCreationForm::FileIOException();
  }
  std::string buffer;
  while (true) {
    std::getline(ifs, buffer);
    if (ifs.eof()) {
      break;
    }
    ofs << buffer << std::endl;
  }
  ifs.close();
  ofs.close();
}
