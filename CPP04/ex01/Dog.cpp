/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:44:12 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/23 15:08:25 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->dogBrain = new Brain();
    std::cout << "Default constructor for Dog has been called" << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original)
{
    std::cout << "Copy constructor for Dog has been called" << std::endl;
    this->dogBrain = new Brain(*original.dogBrain);
}
		
Dog& Dog::operator=(const Dog &original)
{
    std::cout << "Copy assignment constructor for Dog has been called" << std::endl;
    if (this != &original)
    {
        Animal::operator=(original);
    	*this->dogBrain = *original.dogBrain;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructor for Dog has been called" << std::endl;
    delete (dogBrain);
}

void Dog::makeSound() const
{
    std::cout << "The dog has an anouncement: bark bark" << std::endl;
}

Brain *Dog::getBrain(void) const
{
    return (this->dogBrain);
}