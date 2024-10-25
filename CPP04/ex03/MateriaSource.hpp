/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:30:13 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/25 13:22:27 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP


#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*learnedMaterias[4];
	int			numLearnedMaterias;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource	&operator=(const MateriaSource &other);
	virtual ~MateriaSource();

	void		learnMateria(AMateria *m);
	AMateria	*createMateria(const std::string &type);


};

#endif