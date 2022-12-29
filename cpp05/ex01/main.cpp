#include "Bureaucrat.hpp"

void BasicTest() {
    Form one = Form("One", 1, 90);
    Bureaucrat man = Bureaucrat("man", 1);
    std::cout << one;
    man.signForm(one);
}

void GradeLowTest(){
    Form one = Form("One", 1, 90);
    Bureaucrat man = Bureaucrat("man", 30);
    man.signForm(one);
}

void GradeAlreadySignedTest(){
    Form one = Form("One", 36, 90);
    Bureaucrat man = Bureaucrat("man", 30);
    Bureaucrat man2 = Bureaucrat("man2", 34);
    man.signForm(one);
    man2.signForm(one);
}

int main(){
    try {
        // BasicTest();
        // GradeLowTest();
        GradeAlreadySignedTest();
    }
    catch (std::exception & e){
		std::cerr << e.what() << std::endl;
    }
    return 0;
}
