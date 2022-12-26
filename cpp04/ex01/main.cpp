#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void) {
    // // // brain 멤버 변수 확인
    // Brain brain;
    // for (int i = 0; i < 100; i++){
    //     std::cout << i << "번째: "<< brain.getIdea(i) << std::endl;
    // }

    // // 복사 생성 확인
    // Brain copy(brain);
    //  for (int i = 0; i < 100; i++){
    //     std::cout << i << "번째: "<< copy.getIdea(i) << std::endl;
    // }

    // // Animal Array 생성
    // Animal *arr[20];
    // for (int i = 0; i < 10; i++){
    //     std::cout << i << "번째" << std::endl;
    //     arr[i] = new Dog();
    //     arr[i+10] = new Cat();
    // }

    // // delete test
    // for (int i = 0 ; i < 20 ; i++){
    //     std::cout << i << "번째" << std::endl;
    //     delete arr[i];
    // }

    // deep copy test
    Cat cat = Cat();
    Cat copy_cat = cat;
    cat.getBrain()->setIdea(6, "hi");
    std::cout << cat.getBrain()->getIdea(6) << std::endl;
    std::cout << copy_cat.getBrain()->getIdea(6) << std::endl;

    system("leaks Animal");
}
