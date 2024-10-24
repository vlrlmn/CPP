/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:36 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/24 16:25:25 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{

public:
	virtual ~IMateriaSource() {};
	virtual void		learnMateria(AMateria *m) = 0;
	virtual AMateria	*createMateria(const std::string &type) = 0;

};

#endif