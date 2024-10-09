/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:44:12 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/08 17:56:27 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Default constructor for Dog has been called" << std::endl;
}

Dog::Dog(std::string _type)
{
    if (!type.empty())
        this->type = _type;
    std::cout << "Parametrized constructor for Dog has been called" << std::endl;
}

Dog::Dog(const Dog &original)
{
    *this = original;
    std::cout << "Copy constructor for Dog has been called" << std::endl;
}
		
Dog& Dog::operator=(const Dog &original)
{
    if (this != &original)
    	this->type = original.type;
    return *this;
    std::cout << "Copy assignment constructor for Dog has been called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor for Dog has been called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "The dog has an anouncement: bark bark" << std::endl;
}
