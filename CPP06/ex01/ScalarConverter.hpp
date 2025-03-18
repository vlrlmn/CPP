# pragma once

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

class ScalarConverter {
	private:
		ScalarConverter(); 
		ScalarConverter(const ScalarConverter &original);
		ScalarConverter &operator=(const ScalarConverter &original);
		~ScalarConverter();
	public:
		static void convert(const std::string literal);
};

#endif

