#include <iostream>
#include <string>

class Student
{
    private:
        std::string const _login;
    
    public:
        Student() : _login("1default")
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
    Student     *students = new Student[3];

    //Do some stuff here

    delete [] students;
}