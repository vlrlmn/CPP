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

void ScalarConverter::convert(std::string literal) {

}