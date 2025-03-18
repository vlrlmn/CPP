# pragma once

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
	public:
		ScalarConverter(); 
		ScalarConverter(const ScalarConverter &original);
		ScalarConverter &operator=(const ScalarConverter &original);
		~ScalarConverter();
		static void convert(std::string literal);
};

#endif

