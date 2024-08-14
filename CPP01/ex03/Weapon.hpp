/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:46:31 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/14 20:47:01 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon
{
    private:
            std::string type;

    public:
            Weapon();
            Weapon(std::string _type);
            const std::string &getType() const;
            void setType(std::string _type);
};
#endif