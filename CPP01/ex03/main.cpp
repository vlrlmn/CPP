/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:06 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/20 14:36:13 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main() 
{
    {
      Weapon  club = Weapon("crude spiked club");
      HumanA bob("Bob", club);
      bob.attack();
      club.setType("some other type of club");
      bob.attack();
    }
    {
      Weapon  club = Weapon("crude spiked club");
      HumanB jim("Jim");
      jim.setWeapon(club);
      jim.attack();
      club.setType("some other type of club");
      jim.attack();
    }
    return 0; 
}