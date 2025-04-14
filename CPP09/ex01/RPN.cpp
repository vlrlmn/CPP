/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:08:58 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/14 17:11:45 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::~RPN() { }

const RPN &RPN::operator=(const RPN &other)
{
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

RPN::RPN(const RPN &other)
{
	if (this != &other) {
		*this = other;
	}
}

void RPN::readString(const std::string &str) {
	std::istringstream iss(str);
	std::string token;

	while (iss >> token) {
		if (token.length() == 1 && isdigit(token[0])) {
			_tokens.push(token[0]);
		}
		else if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
			_tokens.push(token[0]);
		}
		else {
			throw std::runtime_error("Error: only single-digit numbers and valid operators are allowed");
		}
	}
}


float RPN::rpnEval(void)
{
	float result = 0.0f;
	while(!_tokens.empty()) {
		char ch = _tokens.front();
		_tokens.pop();
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			if (_stack.empty())
			throw(std::runtime_error("Error: not a RPN sequence"));
			float b = _stack.top();	
			_stack.pop();
			if (_stack.empty())
			throw(std::runtime_error("Error: not a RPN sequence"));
			float a = _stack.top();
			_stack.pop();
			result = calculate(a, b, ch);
			_stack.push(result);
		} else if (ch == '(' || ch == ')') {
			throw(std::runtime_error("Error"));
		} else if (isdigit(ch) && (ch >= '0' && ch <= '9')) {
			_stack.push(ch - '0');
		} else {
			throw std::runtime_error("Error: invalid character");
		}
	}
	if (_stack.size() != 1)
    	throw std::runtime_error("Error: too many operands or incomplete expression");

	return _stack.top();

}

float RPN::calculate(float a, float b, char ch) {
	if (ch == '+')
		return a + b;
	if (ch == '-')
		return a - b;
	if (ch == '*')
		return a * b;
	if (ch == '/')
	{
		if (b == 0)
			throw std::logic_error("Division by 0 is not allowed!");
		return a / b;
	}
	return 0.0f;
}