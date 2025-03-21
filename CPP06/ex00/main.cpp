/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:51:26 by vlomakin          #+#    #+#             */
/*   Updated: 2025/03/21 15:51:27 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "No argument!" << std::endl;
		return 1;
	}
	std::string literal = argv[1];
	if (literal.empty())
	{
		std::cout << "Error! argument is empty" << std::endl;
		return 1;
	}
	ScalarConverter::convert(literal);
}