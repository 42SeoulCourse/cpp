#include "Bureaucrat.hpp"

void	testBasic(void)
{
	Bureaucrat	bob("bob", 149);

	std::cout << bob << std::endl;
	bob.decrementGrade();
	std::cout << bob << std::endl;
	bob.incrementGrade();
	bob.incrementGrade();
	bob.incrementGrade();
	std::cout << bob << std::endl;
}

void	testExceptionLow(void)
{
	Bureaucrat	bob("bob", 151);
}

void	testExceptionHigh(void)
{
	Bureaucrat	bob("bob", 0);
}

void	testIncrementGrade(void)
{
	Bureaucrat	bob("bob", 2);
	bob.incrementGrade();
	std::cout << bob << std::endl;
	bob.incrementGrade();
}

void	testDecrementGrade(void)
{
	Bureaucrat	bob("bob", 149);
	bob.decrementGrade();
	std::cout << bob << std::endl;
	bob.decrementGrade();
}

int	main(void)
{
	try
	{
		testBasic();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testExceptionLow();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testExceptionHigh();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		testIncrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testDecrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}