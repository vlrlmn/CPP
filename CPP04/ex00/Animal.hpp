/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:06:05 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/08 18:02:24 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# pragma once

#ifndef AHIMAL_HPP
#define AHIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string _type);
		Animal(const Animal &original);
		Animal & operator=(const Animal &original);
		virtual ~Animal();

        virtual void makeSound() const;
		std::string getType(void) const;
};

#endif