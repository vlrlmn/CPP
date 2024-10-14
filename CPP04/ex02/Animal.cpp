/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:45:24 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/14 16:36:33 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Default constructor for Animal has been called" << std::endl;
}

Animal::Animal(std::string _type)
{
    if (!type.empty())
        this->type = _type;
    std::cout << "Parametrized constructor for Animal has been called" << std::endl;
}

Animal::Animal(const Animal &original)
{
    *this = original;
    std::cout << "Copy constructor for Animal has been called" << std::endl;
}
		
Animal& Animal::operator=(const Animal &original)
{
    if (this != &original)
    	this->type = original.type;
    return *this;
    std::cout << "Copy assignment constructor for Animal has been called" << std::endl;
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
