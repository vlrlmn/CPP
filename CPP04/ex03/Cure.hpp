/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:07:39 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/23 17:09:04 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure : public AMateria
{

public:
	Cure();
	Cure(const std::string &type);
	Cure(const Cure &other);
	Cure	&operator=(const Cure &other);
	~Cure();

	AMateria	*clone() const;
	void		use(ICharacter &target);
};

#endif /* CURE_HPP */