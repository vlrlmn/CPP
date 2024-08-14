/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:02:24 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/14 20:39:52 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weaponType): name(_name), weaponType(_weaponType){};

void HumanA::attack(void) const
{
    std::cout << name << " attacks with their " << weaponType.getType() << std::endl;
}