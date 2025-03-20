# pragma once

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdlib.h>
#include <limits>
#include <cerrno>
#include <iomanip>
#include <float.h>

class ScalarConverter {
	private:
		ScalarConverter(); 
		~ScalarConverter();
	public:
		static void convert(const std::string &literal);
		static void printValues(double value, bool isPseudo);
		static bool isPseudo(const std::string &literal);
		static bool isChar(const std::string &literal);
};

#endif

