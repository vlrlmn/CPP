/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:39:25 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/08 17:29:10 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Default constructor for Cat has been called" << std::endl;
}

Cat::Cat(std::string _type)
{
    if (!type.empty())
        this->type = _type;
    std::cout << "Parametrized constructor for Cat has been called" << std::endl;
}

Cat::Cat(const Cat &original)
{
    *this = original;
    std::cout << "Copy constructor for Cat has been called" << std::endl;
}
		
Cat& Cat::operator=(const Cat &original)
{
     if (this != &original)
    	this->type = original.type;
    return *this;
    std::cout << "Copy assignment constructor for Cat has been called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Destructor for Cat has been called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "The cat has an anouncement: meow meow" << std::endl;
}
