/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:06:05 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/14 16:34:13 by vlomakin         ###   ########.fr       */
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

        virtual void makeSound() const = 0;
		std::string getType(void) const;
};

#endif