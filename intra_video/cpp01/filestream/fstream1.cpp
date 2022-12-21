#include <iostream>
#include <fstream>

int main(void)
{
    std::ifstream   ifs("numbers");
    unsigned int    dst;
    unsigned int    dst2;
    ifs >> dst >> dst2;

    if (!ifs.is_open())
    {
        std::cout << "파일을 열 수가 없습니다!" << std::endl;
        exit(1);
    }
    std::cout << dst << dst2 << std::endl;
    std::cout << "-------------------" << std::endl;

    std::ofstream ofs("test.out");
    ofs << "i like ponies a whole damn lot" << std::endl;
    ofs.close();
}