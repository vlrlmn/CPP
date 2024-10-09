/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:20:39 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/08 17:32:36 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef WRONG_ANIMAL_HPP 
# define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
        WrongAnimal(const std::string _type);
		WrongAnimal(const WrongAnimal &original);
		WrongAnimal &operator=(const WrongAnimal &original);
		virtual ~WrongAnimal();
	
		std::string getType(void) const;
		void makeSound(void) const;
};

#endif