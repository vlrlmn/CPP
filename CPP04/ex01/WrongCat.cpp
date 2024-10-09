/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:39:25 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/08 17:30:46 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "Default constructor for WrongCat has been called" << std::endl;
}

WrongCat::WrongCat(std::string _type)
{
    if (!type.empty())
        this->type = _type;
    std::cout << "Parametrized constructor for WrongCat has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &original)
{
    *this = original;
    std::cout << "Copy constructor for WrongCat has been called" << std::endl;
}
		
WrongCat& WrongCat::operator=(const WrongCat &original)
{
     if (this != &original)
    	this->type = original.type;
    return *this;
    std::cout << "Copy assignment constructor for WrongCat has been called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor for WrongCat has been called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "The WrongCat has an anouncement: wrong meow" << std::endl;
}
