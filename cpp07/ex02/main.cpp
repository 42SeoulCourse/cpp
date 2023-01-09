#include "Array.hpp"

// normal test
int main(){
	Array<std::string> arr(3);

	std::cout << arr.size() << std::endl;

	arr[0] = std::string("Yes");
	arr[1] = std::string(", it's CpP");
	arr[2] = std::string("07");

	std::cout << arr[0] <<  arr[1] << arr[2] << std::endl;
	Array<std::string> arr_2(arr);

	arr[0] = std::string("Last");
	arr[1] = std::string("~~~~");
	arr[2] = std::string("Oh yeeeeee");

	std::cout << arr_2[0] << arr_2[1] << arr_2[2] << std::endl;
}


// index range
// int main(){
// 	try {
// 		Array<int> arr(3);
// 		std::cout << arr[4];
// 	}
// 	catch (std::exception & e){
// 		std::cout << e.what() << std::endl;
// 	}
// }
