/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:05:49 by vlomakin          #+#    #+#             */
/*   Updated: 2024/10/09 14:25:58 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
int Fixed::toInt( void ) const
{
	return (fixedNum >> fractBits);
}

float Fixed::toFloat( void ) const
{
	return ((float)fixedNum / (1 << fractBits));
}

Fixed::Fixed(const int intNum)
{
	std::cout << "Int constructor called" << std::endl;
	fixedNum = (intNum * (1 << fractBits));
}
Fixed::Fixed(const float floatNum)
{
	std::cout << "Float constructor called" << std::endl;
	fixedNum = roundf(floatNum * (1 << fractBits));
}

Fixed::Fixed() : fixedNum(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = original;
}

Fixed& Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
    	this->fixedNum = original.fixedNum;
    return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}