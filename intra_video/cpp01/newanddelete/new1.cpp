#include <iostream>
#include <string>

class Student
{
    private:
        std::string const _login;
    
    public:
        Student(std::string const login) : _login(login)
        {
            std::cout << "Student " << this->_login << " is born" << std::endl;
        }

        ~Student(void)
        {
            std::cout << "student " << this->_login << " died" << std::endl;
        }
};

int main(void)
{
    Student     bob = Student("bfubar"); //stack 에 할당
    Student     *jim = new Student("jfubar"); //heap 에 동적할당

    //Do some stuff here

    delete jim; //jim is destroyed
    return (0); //bob is destroyed
}