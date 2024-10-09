/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:12:53 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/02 17:46:42 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
    ClapTrap clap("ClapBot");
    clap.attack("target1");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << std::endl;

    ScavTrap scav("ScavBot");
    scav.attack("target2");
    scav.guardGate();

    std::cout << std::endl;

    FragTrap frag("FragBot");
    frag.attack("target3");
    frag.highFivesGuys();

    std::cout << std::endl;


    FragTrap fragCopy(frag);
    fragCopy.highFivesGuys();

    std::cout << std::endl;

    ScavTrap scav2;
    scav2 = scav;
    scav2.attack("target4");

    return 0;
}
