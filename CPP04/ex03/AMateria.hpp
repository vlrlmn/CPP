/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:01:16 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/23 17:09:02 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
protected:
    std::string	type;
public:
    AMateria();
	AMateria(const std::string &type);
	AMateria(const AMateria &other);
	AMateria	&operator=(const AMateria &other);
	virtual ~AMateria();

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
}

#endif