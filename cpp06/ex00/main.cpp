#include "Conversion.hpp"

int main(int argc, char **argv)
{
	Conversion conversion;
	if (argc != 2)
	{
		std::cout << "No viable argument provided ! Usage: ./convert [arg]" << std::endl;
		return 0;
	}
	try {
		conversion.detectType(argv[1]);
		conversion.convertData();
		conversion.printData();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cout << "Conversion aborted because of the reason above. Check back your args !" << std::endl;
	}
	return 0;
}