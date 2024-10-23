/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICaracter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:08:26 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/23 17:08:59 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include <string>

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {};
	virtual const std::string	&getName() const = 0;

	virtual void	equip(AMateria *m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter &target) = 0;

};

#endif