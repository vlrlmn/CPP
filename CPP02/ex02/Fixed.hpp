/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:18:23 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/09/30 16:29:14 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed {
	private:
		int fixedNum;
		static const int fractBits = 8;

	public:
		Fixed();
		Fixed(const int intNum);
		Fixed(const float floatNum);
		Fixed(const Fixed &original);
		Fixed & operator=(const Fixed &original);
		~Fixed();
	
		float toFloat( void ) const;
		int toInt( void ) const;

        bool operator>(const Fixed& val) const;
        bool operator<(const Fixed& val) const;
        bool operator>=(const Fixed& val) const;
        bool operator<=(const Fixed& val) const;
        bool operator!=(const Fixed& val) const;
        bool operator==(const Fixed& val) const;

        Fixed operator+(const Fixed& val);
        Fixed operator-(const Fixed& val);
        Fixed operator*(const Fixed& val);
        Fixed operator/(const Fixed& val);
    
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed &min (Fixed &val1, Fixed &val2);
        static const Fixed &min (const Fixed &val1, const Fixed &val2);
        static Fixed &max (Fixed &val1, Fixed &val2);
        static const Fixed &max (const Fixed &val1, const Fixed &val2);
        int getFixedPointValue(void) const;
};
	std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif