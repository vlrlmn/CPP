/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:44:12 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/14 16:41:11 by vlomakin         ###   ########.fr       */
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
        Animal::operator=(original);
    	*this->dogBrain = *original.dogBrain;
    }
    return *this;
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