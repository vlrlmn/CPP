/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:09:01 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/08 21:09:09 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#ifndef RPN_HPP
#define RPN_HPP

# include <stack>
# include <queue>
# include <sstream>
# include <iostream>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		const RPN &operator=(const RPN &other);
		void readString(const std::string &str);
		float rpnEval(void);
		float calculate(float a, float b, char ch);
	private:
		std::stack<float> _stack;
		std::queue<char> _tokens;
};

#endif