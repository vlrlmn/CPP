/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:05:49 by vlomakin          #+#    #+#             */
/*   Updated: 2024/10/09 13:54:31 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : FixedNum(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
    FixedNum = original.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
        this->FixedNum = original.getRawBits();
    return *this;
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
	std::cout <<  "setRawBits member function called" << std::endl;
	FixedNum = raw;
}