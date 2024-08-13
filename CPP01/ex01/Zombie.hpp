/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:25:38 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/13 21:12:01 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
            std::string name;
    
    public:
            Zombie();
            Zombie(std::string name);
            ~Zombie();

            void announce(void);
            void setName(std::string _name);
};

Zombie*    zombieHorde( int N, std::string name );

#endif