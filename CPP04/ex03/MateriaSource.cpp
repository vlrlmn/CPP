/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:30:25 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/25 16:42:36 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	numLearnedMaterias = 0;
	for (int i = 0; i < 4; i++)
		learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	numLearnedMaterias = other.numLearnedMaterias;
	for (int i = 0; i < 4; i++)
		learnedMaterias[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (other.learnedMaterias[i])
		{
			learnedMaterias[i] = other.learnedMaterias[i]->clone();
		}
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i])
		{
			delete learnedMaterias[i];
			learnedMaterias[i] = NULL;
		}
	}
	for (int i =0; i < 4; i++)
	{
		if (other.learnedMaterias[i])
		{
			learnedMaterias[i] = other.learnedMaterias[i]->clone();
		}
	}
	numLearnedMaterias = other.numLearnedMaterias;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i])
			delete learnedMaterias[i];
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (numLearnedMaterias >= 4)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i] == NULL)
		{
			learnedMaterias[i] = m->clone();
			numLearnedMaterias++;
			break;
		}
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	if (numLearnedMaterias == 0)
		return ( NULL );
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i] && learnedMaterias[i]->getType() == type)
		{
			return (learnedMaterias[i]->clone());
		}
	}
    std::cout << "Unexisting type: " << type << "! There are only Ice and Cure materias!" << std::endl;
	return (NULL);
}
