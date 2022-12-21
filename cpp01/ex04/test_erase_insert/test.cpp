#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	std::ifstream		infile(argv[1]);
	std::string		file_content;
	char c;
	int i = 0;

	while (infile.get(c)) {
		file_content.push_back(c);
	}
	i = file_content.find("bb");
	file_content.erase(i, 2);
	// file_content.insert(i, "aac");
	std::cout << file_content << std::endl;
	return (0);
}