/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:05:54 by vlomakin          #+#    #+#             */
/*   Updated: 2024/10/09 14:05:03 by vlomakin         ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
	
#endif