/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:45:24 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/11 12:47:03 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Default constructor for Animal has been called" << std::endl;
}

Animal::Animal(std::string _type)
{
    if (!_type.empty())
        this->type = _type;
    std::cout << "Parametrized constructor for Animal has been called" << std::endl;
}

Animal::Animal(const Animal &original)
{
    *this = original;
    std::cout << "Copy constructor for Animal has been called" << std::endl;
}
		
const Animal& Animal::operator=(const Animal &original)
{
    std::cout << "Copy assignment constructor for Animal has been called" << std::endl;
    if (this != &original)
    	this->type = original.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor for Animal has been called" << std::endl;
}

std::string Animal::getType(void) const
{
    std::cout << "Animal getType() function was called. The type is " << this->type << std::endl;
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "Animal was triggered and it makes sound" << std::endl;
}
