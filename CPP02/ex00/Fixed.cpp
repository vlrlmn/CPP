/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:05:49 by vlomakin          #+#    #+#             */
/*   Updated: 2024/09/18 16:28:40 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractBits = 8;

Fixed::Fixed() : FixedNum(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &original) : FixedNum(original.FixedNum) 
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
        FixedNum = original.FixedNum;
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout <<  "getRawBits member function called" << std::endl;
	return FixedNum;
}

void Fixed::setRawBits( int const raw )
{
	std::cout <<  "setRawBits member function called" << std::endl;
	FixedNum = raw;
}