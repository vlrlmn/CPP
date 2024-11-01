/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:12:53 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/14 15:24:09 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
    std::cout << "\n--- Testing ClapTrap ---" << std::endl;
    ClapTrap clap("ClapBot");
    clap.attack("target1");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << std::endl;

    std::cout << "\n--- Testing ScavTrap ---" << std::endl;
    ScavTrap scav("ScavBot");
    scav.attack("target2");
    scav.guardGate();

    std::cout << std::endl;

    std::cout << "\n--- Testing FragTrap ---" << std::endl;
    FragTrap frag("FragBot");
    frag.attack("target3");
    frag.highFivesGuys();

    std::cout << std::endl;

    FragTrap fragCopy(frag);
    fragCopy.highFivesGuys();

    std::cout << std::endl;

    std::cout << "\n--- Testing ScavTrap ---" << std::endl;
    ScavTrap scav2;
    scav2 = scav;
    scav2.attack("target4");

    std::cout << "\n--- End of Tests ---" << std::endl;
    return 0;
}
