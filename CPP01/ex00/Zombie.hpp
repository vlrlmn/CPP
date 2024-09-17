/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:09:42 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/09/17 14:58:46 by vlomakin         ###   ########.fr       */
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
            Zombie(std::string name);
            ~Zombie();

            void announce(void);
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif