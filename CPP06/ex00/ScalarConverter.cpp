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

void convertFloat(const std::string literal) {

	float num = atof(literal.c_str());

	std::cout << "char: " << literal[0] << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << std::fixed << std::cout.precision(1) << num << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::cout.precision(1) << static_cast<double>(num) << std::endl;
}

void convertPseudo(const std::string literal) {

}

bool isPseudo(const std::string literal)
{
	return (literal == "-inff" || literal == "+inff" || literal == "nanf");
}
void ScalarConverter::convert(const std::string literal) {

	if (isPseudo(literal))
		convertPseudo(literal);
	std::string::const_iterator it;
	for (it = literal.begin(); it != literal.end(); ++it)
	{
		if (std::isspace(*it))
			return ;
	}

	if (std::isalpha(literal[0]) && literal.length() == 1)
		convertChar(literal);
	else if (literal[literal.length() - 1] == 'f')
		convertFloat(literal);
}