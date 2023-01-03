#include "Intern.hpp"

int main(){

    Intern  someRandomIntern;
    Form*   rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

    Bureaucrat woman = Bureaucrat("woman", 20);
    woman.signForm(*rrf);
    woman.executeForm(*rrf);

    // Form *no_name = someRandomIntern.makeForm("good", "target");
    // (void) no_name;
    // "presidential pardon", "robotomy request", "shrubbery creation"
}