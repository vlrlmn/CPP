#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called for Scalar Converter" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &original) {
	std::cout << "Copy constructor called for Scalar Converter" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &original) {
	std::cout << "Copy assignment constructor called for Scalar Converter" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called for Scalar Converter" << std::endl;
}

void convertChar(const std::string literal) {
	std::cout << "char: " << literal[0] << std::endl;
	std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::cout.precision(1) << static_cast<float>(literal[0]) << std::endl;
	std::cout << "double: " << std::fixed << std::cout.precision(1) << static_cast<double>(literal[0]) << std::endl;
}

void ScalarConverter::convert(const std::string literal) {
	if (std::isalpha(literal[0]) && literal.length() == 1)
		convertChar(literal);
}