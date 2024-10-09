/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:06:05 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/08 17:32:40 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string _type);
		Dog(const Dog &original);
		Dog & operator=(const Dog &original);
		~Dog();

		void makeSound() const;
};

#endif