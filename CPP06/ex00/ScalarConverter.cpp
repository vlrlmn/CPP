#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called for Scalar Converter" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called for Scalar Converter" << std::endl;
}

bool ScalarConverter::isPseudo(const std::string &literal) {
    return (literal == "-inf" || literal == "+inf" || literal == "-inff" 
            || literal == "+inff" || literal == "nan" || literal == "nanf");
}


bool ScalarConverter::isChar(const std::string &literal) {
	return literal.length() == 1 && std::isalpha(literal[0]);
}

void ScalarConverter::convert(const std::string &literal) {
	if (isChar(literal))
	{
		printValues(static_cast<double>(literal[0]), false);
		return; 
	}
	std::string tempLiteral = literal;
	for(size_t i = 0; tempLiteral[i]; i++) {
		if (std::isupper(tempLiteral[i]))
			tempLiteral[i] = std::tolower(tempLiteral[i]);
	}

	if (isPseudo(tempLiteral)) {
		double value = std::strtod(tempLiteral.c_str(), NULL);
		bool isFloat = (tempLiteral == "+inff" || tempLiteral == "-inff" || tempLiteral == "nanf" || tempLiteral == "+inf" || tempLiteral == "-inf");
		if (tempLiteral == "+inff" || tempLiteral == "-inff" || tempLiteral == "nanf")
			printValues(value, isFloat);
		else
			printValues(value, isFloat);
		return;
	}

	char *endPtr;
	errno = 0;
	long double lvalue = std::strtod(literal.c_str(), &endPtr);
	if (errno == ERANGE || lvalue == HUGE_VAL || lvalue == -HUGE_VAL 
		|| lvalue == -HUGE_VALL || lvalue == HUGE_VALL|| lvalue == -HUGE_VALF|| lvalue == HUGE_VALF) {
		std::cerr << "Error: overflow or underflow" << std::endl;
		return;
	}
	double value = static_cast<double>(lvalue); 
    if (*endPtr == 'f') {
		if (literal.find('.') == std::string::npos)
		{
			std::cerr << "Invalid input" << std::endl;
			return;
		}
        endPtr++;
	}
    if (*endPtr != '\0' && *endPtr != 'f') {
		std::cerr << "Invalid input" << std::endl;
        return;
    }
	if (errno == ERANGE || value > DBL_MAX || value < -DBL_MAX) {
		std::cerr << "Error: overflow or underflow" << std::endl;
		return ;
	}
	printValues(value, false);
}

void ScalarConverter::printValues(double value, bool isPseudo) {
    if (isPseudo) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        std::cout << std::showpos;

        if (value != value) {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } 
        else if (value == HUGE_VAL) {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        } 
        else if (value == -HUGE_VAL) {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        std::cout << std::noshowpos; 
        return;
    }
	
	// Char
    if (value < CHAR_MIN || value > CHAR_MAX || value != value)
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	
	//Int
    if (value < INT_MIN || value > INT_MAX || value != value)
        std::cout << "int: impossible" << std::endl;
    else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	
	//Float
	std::cout << std::fixed << std::setprecision(1);
	if (value > FLT_MAX || value < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else {
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	}

	//Double
	std::cout << "double: " << value << std::endl;
}
