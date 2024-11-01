/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:22:50 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/24 16:23:39 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	type = "cure";
}

Cure::Cure(const std::string &type) : AMateria(type) {}

Cure::Cure(const Cure &other) : AMateria(other) {}

Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Cure::~Cure() {}

AMateria	*Cure::clone() const
{
	return (new Cure(type));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

