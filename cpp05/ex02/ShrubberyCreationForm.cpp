#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("SC", SC_GRADE_TO_SIGN, SC_GRADE_TO_EXEC), target("Default") {
  // std::cout << "ShrubberyCreationForm created. Default." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("SC", SC_GRADE_TO_SIGN, SC_GRADE_TO_EXEC), target(target) {
  // std::cout << "ShrubberyCreationForm created. Default." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : target(src.getTarget()) {
  // std::cout << "Copy constructor called. " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  // std::cout << "ShrubberyCreationForm destroyed." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& rhs) {
  if (this != &rhs) {
    this->target = rhs.target;
  }
  return *this;
}

void  ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned()) {
    throw AForm::InvalidSignCondition();
    return;
  }
  if (executor.getGrade() > this->getGradeToExecute()) {
    throw AForm::GradeTooLowException();
    return;
  }
  std::ifstream ifs("ASCII.txt");
  if (!ifs.good()) {
    throw ShrubberyCreationForm::FileIOException();
  }
  std::ofstream ofs(std::string(this->target) + "_shrubbery");
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
