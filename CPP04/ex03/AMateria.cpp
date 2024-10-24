/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:01:18 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/24 16:22:09 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria(const AMateria &other)
{
	type = other.type;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

AMateria::~AMateria() {}

const std::string	&AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}