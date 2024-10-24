/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:44:12 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/24 16:06:04 by lomakinaval      ###   ########.fr       */
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
    if (this != &original && original.dogBrain)
    {
        this->dogBrain = new Brain(*original.dogBrain);
    }
}
		
Dog& Dog::operator=(const Dog &original)
{
    std::cout << "Copy assignment constructor for Dog has been called" << std::endl;
    if (this != &original)
    {
        std::cout << "HERE 1" << std::endl;
        AAnimal::operator=(original);
        std::cout << "HERE 2" << std::endl;
        delete this->dogBrain;
        std::cout << "HERE 3 " << std::endl;
    	this->dogBrain = new Brain(*original.dogBrain);
        std::cout << "HERE 4" << std::endl;
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