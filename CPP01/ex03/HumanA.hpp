/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:01:21 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/14 20:46:47 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
    private: 
            Weapon &weaponType;
            std::string name;
    public:
            HumanA(std::string _name, Weapon& _weaponType);
            void attack() const;
            
};
#endif