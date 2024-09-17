/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:02:24 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/20 14:05:45 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weaponType): name(_name), weaponType(_weaponType){};

void HumanA::attack(void) const
{
    std::cout << name << " attacks with their " << weaponType.getType() << std::endl;
}