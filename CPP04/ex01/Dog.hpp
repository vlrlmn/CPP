/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:06:05 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/11 12:28:53 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{	private:
		Brain* dogBrain;
	public:
		Dog();
		Dog(const Dog &original);
		Dog & operator=(const Dog &original);
		~Dog();

		void makeSound() const;
		Brain *getBrain(void) const;
};

#endif