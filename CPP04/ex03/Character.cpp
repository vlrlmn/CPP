/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:32:51 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/29 10:57:33 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character() : name(""), queue()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}


Character::Character(const std::string &name) : name(name), queue()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;

}

Character::Character(const Character &other)
{
	name = other.name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
		{
			inventory[i] = other.inventory[i]->clone();
		}
	}
}

Character	&Character::operator=(const Character &other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
		{
			inventory[i] = other.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete  inventory[i];
		}
	}
	while (!queue.isEmpty())
	{
		AMateria	*val = (AMateria *)queue.dequeue();
		delete val;
	}
}

const std::string	&Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
    if (m == NULL)
        return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m->clone();
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx])
	{
		queue.enqueue(inventory[idx]);
		inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx])
		inventory[idx]->use(target);
}