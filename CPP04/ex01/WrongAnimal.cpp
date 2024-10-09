/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:45:24 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/08 17:15:13 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "Default constructor for WrongAnimal has been called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type)
{
    if (!type.empty())
        this->type = _type;
    std::cout << "Parametrized constructor for WrongAnimal has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original)
{
    *this = original;
    std::cout << "Copy constructor for WrongAnimal has been called" << std::endl;
}
		
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &original)
{
    if (this != &original)
    	this->type = original.type;
    return *this;
    std::cout << "Copy assignment constructor for WrongAnimal has been called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor for WrongAnimal has been called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    std::cout << "WrongAnimal getType() function was called. The type is " << this->type << std::endl;
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal was triggered and it makes sound" << std::endl;
}
