/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:29:02 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/14 20:19:09 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(): type(""){}

Weapon::Weapon(std::string _type): type (_type){}

const std::string &Weapon::getType(void) const
{
    return(type);
}

void Weapon::setType(std::string _type)
{
    type = _type;
}