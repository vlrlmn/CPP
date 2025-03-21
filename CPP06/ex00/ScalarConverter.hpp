/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:51:33 by vlomakin          #+#    #+#             */
/*   Updated: 2025/03/21 15:51:34 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cerrno>
#include <iomanip>
#include <cfloat>
#include <cmath>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj); 
		ScalarConverter &operator=(const ScalarConverter &obj); 
		~ScalarConverter();
	public:
		static void convert(const std::string &literal);
		static void printValues(double value, bool isPseudo);
		static bool isPseudo(const std::string &literal);
		static bool isChar(const std::string &literal);
};

#endif

