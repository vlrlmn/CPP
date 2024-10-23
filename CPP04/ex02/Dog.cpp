/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:44:12 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/23 16:49:25 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    this->type = "Dog";
    this->dogBrain = new Brain();
    std::cout << "Default constructor for Dog has been called" << std::endl;
}

Dog::Dog(const Dog &original) : AAnimal(original)
{
    std::cout << "Copy constructor for Dog has been called" << std::endl;
    if (this != &original)
    {
        this->dogBrain = new Brain();
        *this->dogBrain = *original.dogBrain;
    }
}
		
Dog& Dog::operator=(const Dog &original)
{
    std::cout << "Copy assignment constructor for Dog has been called" << std::endl;
    if (this != &original)
    {
        AAnimal::operator=(original);
        delete this->dogBrain;
    	this->dogBrain = new Brain(*original.dogBrain);
    }
	return (*this);
}

Dog::~Dog()
{
    std::cout << "Destructor for Dog has been called" << std::endl;
    delete dogBrain;
}

void Dog::makeSound() const
{
    std::cout << "The dog has an anouncement: bark bark" << std::endl;
}

Brain *Dog::getBrain(void) const
{
    return (this->dogBrain);
}