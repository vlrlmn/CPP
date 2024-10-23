/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:45:24 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/23 16:19:01 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal()
{
    type = "Animal";
    std::cout << "Default constructor for Animal has been called" << std::endl;
}

AAnimal::AAnimal(std::string _type)
{
    if (!type.empty())
        this->type = _type;
    std::cout << "Parametrized constructor for Animal has been called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &original)
{
    *this = original;
    std::cout << "Copy constructor for Animal has been called" << std::endl;
}
		
AAnimal& AAnimal::operator=(const AAnimal &original)
{
    if (this != &original)
    	this->type = original.type;
    return *this;
    std::cout << "Copy assignment constructor for Animal has been called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor for Animal has been called" << std::endl;
}

std::string AAnimal::getType(void) const
{
    std::cout << "Animal getType() function was called. The type is " << this->type << std::endl;
    return (this->type);
}

void AAnimal::makeSound() const
{
    std::cout << "Animal was triggered and it makes sound" << std::endl;
}
