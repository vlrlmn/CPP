/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:39:25 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/23 16:21:14 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->catBrain = new Brain();
    std::cout << "Default constructor for Cat has been called" << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original)
{
    std::cout << "Copy constructor for Cat has been called" << std::endl;
    this->catBrain = new Brain(*original.catBrain);
}
		
Cat& Cat::operator=(const Cat &original)
{
    if (this != &original)
    {
        Animal::operator=(original);
        delete this->catBrain;
    	this->catBrain = new Brain(*original.catBrain);
    }
    std::cout << "Copy assignment constructor for Cat has been called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Destructor for Cat has been called" << std::endl;
    delete (catBrain);
}

void Cat::makeSound() const
{
    std::cout << "The cat has an anouncement: meow meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
    return (this->catBrain);
}