/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:06:05 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/11 12:28:46 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* catBrain;
	public:
		Cat();
		Cat(const Cat &original);
		Cat & operator=(const Cat &original);
		~Cat();

		void makeSound() const;
		Brain *getBrain(void) const;
		
};

#endif