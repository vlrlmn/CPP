#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "No argument!" << std::endl;
	std::string literal = argv[1];
	if (literal.empty())
	{
		std::cout << "Error! argument is empty" << std::endl;
		return 1;
	}
	ScalarConverter::convert(literal);
}