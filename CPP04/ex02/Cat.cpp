/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:39:25 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/23 16:33:29 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    this->type = "Cat";
    this->catBrain = new Brain();
    std::cout << "Default constructor for Cat has been called" << std::endl;
}

Cat::Cat(const Cat &original) : AAnimal(original)
{
    std::cout << "Copy constructor for Cat has been called" << std::endl;
    if (this != &original)
    {
        this->catBrain = new Brain();
        *this->catBrain = *original.catBrain;
    }
}
		
Cat& Cat::operator=(const Cat &original)
{
    if (this != &original)
    {
        AAnimal::operator=(original);
        delete this->catBrain;
    	this->catBrain = new Brain(*original.catBrain);
    }
    std::cout << "Copy assignment constructor for Cat has been called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Destructor for Cat has been called" << std::endl;
    delete catBrain;
}

void Cat::makeSound() const
{
    std::cout << "The cat has an anouncement: meow meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
    return (this->catBrain);
}