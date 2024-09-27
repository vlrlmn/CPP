/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:32:05 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/09/27 17:05:23 by lomakinaval      ###   ########.fr       */
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
	fixedNum = (intNum * (1 << fractBits));
}
Fixed::Fixed(const float floatNum)
{
	fixedNum = roundf(floatNum * (1 << fractBits));
}

Fixed::Fixed() : fixedNum(0) {}

Fixed::Fixed(const Fixed &original)
{
    *this = original;
}

Fixed& Fixed::operator=(const Fixed &original)
{
    if (this != &original)
    	this->fixedNum = original.fixedNum;
    return *this;
}

Fixed::~Fixed() {}

int	Fixed::getFixedPointValue(void) const
{
	return (fixedNum);
}

bool Fixed::operator>(const Fixed& val) const
{
    return (this->fixedNum > val.fixedNum);
}
bool Fixed::operator<(const Fixed& val) const
{
    return (this->fixedNum < val.fixedNum);
}

bool Fixed::operator>=(const Fixed& val) const
{
    return (this->fixedNum >= val.fixedNum);
}

bool Fixed::operator<=(const Fixed& val) const
{
    return (this->fixedNum <= val.fixedNum);
}

bool Fixed::operator!=(const Fixed& val) const
{
    return (this->fixedNum != val.fixedNum);
}

bool Fixed::operator==(const Fixed& val) const
{
    return (this->fixedNum == val.fixedNum);
}

Fixed Fixed::operator+(const Fixed& val)
{
    Fixed copy;
    copy.fixedNum =  this->fixedNum + val.fixedNum / (1 << fractBits);

    return (copy);
}

Fixed Fixed::operator-(const Fixed& val)
{
    Fixed copy;
    copy.fixedNum =  this->fixedNum - val.fixedNum / (1 << fractBits);

    return (copy);
}

Fixed Fixed::operator*(const Fixed& val)
{
    Fixed copy;
    copy.fixedNum =  this->fixedNum * val.fixedNum / (1 << fractBits);

    return (copy);
}

Fixed Fixed::operator/(const Fixed& val)
{
    Fixed copy;
    copy.fixedNum =  this->fixedNum / val.fixedNum / (1 << fractBits);

    return (copy);
}

Fixed& Fixed::operator++() {
    this->fixedNum += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->fixedNum += 1;
    return temp;
}

Fixed& Fixed::operator--() {
    this->fixedNum -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->fixedNum -= 1;
    return temp;
}

Fixed &Fixed::min (Fixed &val1, Fixed &val2)
{
    return (val1 < val2 ? val1 : val2);
}

const Fixed &Fixed::min (const Fixed &val1, const Fixed &val2)
{
    if (val1.getFixedPointValue() < val2.getFixedPointValue())
		return (val1);
	else
	 	return (val2);
}

Fixed &Fixed::max (Fixed &val1, Fixed &val2)
{
    return (val1 > val2 ? val1 : val2);
}

const Fixed &Fixed::max (const Fixed &val1, const Fixed &val2)
{
      if (val1.getFixedPointValue() < val2.getFixedPointValue())
		return (val2);
	else
	 	return (val1);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}