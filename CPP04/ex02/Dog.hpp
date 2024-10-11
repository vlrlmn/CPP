/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:06:05 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/09 16:00:19 by vlomakin         ###   ########.fr       */
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
		Dog(const std::string _type);
		Dog(const Dog &original);
		Dog & operator=(const Dog &original);
		~Dog();

		void makeSound() const;
};

#endif