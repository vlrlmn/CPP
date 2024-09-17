/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:05:54 by vlomakin          #+#    #+#             */
/*   Updated: 2024/09/17 17:27:12 by vlomakin         ###   ########.fr       */
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
		Fixed(int FixedNum);
		Fixed(const Fixed &cp);
		Fixed & operator=(const Fixed &);
		~Fixed();
	
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif