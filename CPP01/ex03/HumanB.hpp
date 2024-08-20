/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:03:40 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/15 14:35:04 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private: 
            Weapon *weaponType;
            std::string name;
    public:
            HumanB(std::string _name);
            void attack() const;
            void setWeapon(Weapon &weaponType);
};
#endif