/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:08:47 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/14 17:26:47 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
	if (argc !=2) {
		std::cout << "Error: 2 arguments needed" << std::endl;
		return 1;
	}
	RPN rpn;
	try {
		rpn.readString(argv[1]);
		std::cout << rpn.rpnEval() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}