/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:05:54 by vlomakin          #+#    #+#             */
/*   Updated: 2024/09/18 15:57:55 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int FixedNum;
		static const int FractBits;

	public:
		Fixed();
		Fixed(const Fixed &original);
		Fixed & operator=(const Fixed &original);
		~Fixed();
	
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif