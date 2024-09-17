/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:05:49 by vlomakin          #+#    #+#             */
/*   Updated: 2024/09/17 18:13:29 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractBits = 0;

Fixed::Fixed(int FixedNum): FixedNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &cp): FixedNum(cp.FixedNum)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &cp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	std::cout << cp.FixedNum << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout <<  "getRawBits member function called" << std::endl;
	return (FixedNum);
}

void Fixed::setRawBits( int const raw )
{
	std::cout <<  "getRawBits member function called" << std::endl;
	FixedNum = raw;
}