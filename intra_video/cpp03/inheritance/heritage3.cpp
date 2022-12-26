#include <string>

class Animal // name, run(), legs 에 접근 가능
{
    private:
     std::string name; // Animal 객체에서마 접근 가능

    protected:
     Leg legs[4]; // Animal 과 자식 객체에서 접근 가능

    public:
     void run(); // 어디서나 접근 가능
};

class Dog : public Animal // run(), legs 접근 가능
{

};

int main() // run() 만 접근 가능
{

}