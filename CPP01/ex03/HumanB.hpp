/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:03:40 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/14 20:46:53 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

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