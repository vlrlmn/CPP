/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:25:38 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/20 13:51:44 by vlomakin         ###   ########.fr       */
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