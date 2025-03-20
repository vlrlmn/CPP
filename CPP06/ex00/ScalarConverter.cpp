#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called for Scalar Converter" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &original) {
	std::cout << "Copy constructor called for Scalar Converter" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &original) {
	std::cout << "Copy assignment constructor called for Scalar Converter" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called for Scalar Converter" << std::endl;
}

bool isPseudo(const std::string literal)
{
	return (literal == "-inf" || literal == "+inf" || literal == "-inff" 
		|| literal == "+inff" || literal == "nan" || literal == "nanf");
	}
	
void ScalarConverter::convert(const std::string &literal) {
	if (isPseudo(literal))
		printValue(literal, true);
	
		char *endPtr;
		errno = 0;
		double value = std::strtod(literal.c_str(), &endPtr);

		if (*endPtr != '\0' && *endPtr != 'f')
		{
			std::cerr << "Invalid input" << std::endl;
			return ;
		}
		if (errno == ERANGE)
		{
			std::cerr << "Error: overflow or undefflow" << std::endl;
			return ;
		}
		printValue(literal, false);
}

void printValue(const std::string literal, bool isPseudo) {

}