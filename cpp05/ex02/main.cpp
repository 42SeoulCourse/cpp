#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
        // PP
    // Bureaucrat man = Bureaucrat("man", 20);
    // PresidentialPardonForm pp = PresidentialPardonForm("target1");

    // man.signForm(pp);
    // man.executeForm(pp);

    // RR
    Bureaucrat woman = Bureaucrat("woman", 20);
    RobotomyRequestForm rr = RobotomyRequestForm("target2");
    woman.signForm(rr);
    woman.executeForm(rr);

    // SC 아스키파일 필요
    // Bureaucrat human = Bureaucrat("woman", 20);
    // ShrubberyCreationForm sc = ShrubberyCreationForm("target3");
    // human.signForm(sc);
    // human.executeForm(sc);


    
    return 0;
}