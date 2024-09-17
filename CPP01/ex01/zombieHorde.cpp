/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:26:03 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/20 13:59:45 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name )
{
    Zombie *nZombies = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        nZombies[i].setName(name);
    }
    return(nZombies);
}
