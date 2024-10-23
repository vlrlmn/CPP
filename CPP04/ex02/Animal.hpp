/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:06:05 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/23 16:59:31 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef AHIMAL_HPP
#define AHIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(std::string _type);
		AAnimal(const AAnimal &original);
		AAnimal & operator=(const AAnimal &original);
		virtual ~AAnimal();

        virtual void makeSound() const = 0;
		std::string getType(void) const;
};

#endif