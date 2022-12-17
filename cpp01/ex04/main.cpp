#include <iostream>
#include <fstream>

static int	isAcValid(const int ac)
{
	if (ac != 4) {
        std::cout << "usage: ./replace <filename> <oldstring> <newstring>" << std::endl;
		return (false);
	}
	return (true);
}

static int	isAvValid(char **av, const std::string find, const std::string replace)
{
	if (!std::string(av[1]).length() || !find.length() || !replace.length()) {
		std::cout << "Please use non-empty value" << std::endl;
		return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	if (!isAcValid(ac))
		exit(1);

	std::ifstream	ifs(av[1]);
    std::string    	find = av[2];
    std::string    	replace = av[3];
	
	if (!ifs.good()) {
		std::cout << "Fail to open a file" << std::endl;
		exit(1);
	}
	if (!isAvValid(av, find, replace) || !ifs.good())
		exit(1);

	std::string		file_content;
    std::ofstream 	ofs(std::string(av[1]) + ".replace");
	char			character;

	while (!ifs.get(character).eof()) {
		file_content.push_back(character);
	}

	int	i;
	i = file_content.find(find);
	while (i != -1)
	{
		file_content.erase(i, find.length());
		file_content.insert(i, replace);
		i = file_content.find(find);
	}
	
	ofs << file_content;
	ifs.close();
    ofs.close();	
	return (0);
}