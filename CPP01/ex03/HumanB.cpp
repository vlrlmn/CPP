/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:02:27 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/14 20:46:06 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB(std::string _name): name(_name), weaponType(NULL) {};

void HumanB::setWeapon(Weapon &weapon)
{
    this->weaponType = &weapon;
}

void HumanB::attack() const
{
    if (weaponType == NULL)
        std::cout << name << " attacks without weapon" << std::endl;
    else
        std::cout << name << " attacks with their " << weaponType << std::endl;
}