/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:12:53 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/14 15:24:51 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main() {

    std::cout << "\n--- Testing ClapTrap ---" << std::endl;
    ClapTrap clap1("ClapOne");
    ClapTrap clap2("ClapTwo");

    clap1.attack("EnemyOne");
    clap2.takeDamage(3);
    clap2.beRepaired(5);


    ClapTrap clap3(clap1);
    ClapTrap clap4;
    clap4 = clap2;

    std::cout << "\n--- Testing FragTrap ---" << std::endl;
    FragTrap frag1("FragOne");
    frag1.attack("EnemyTwo");
    frag1.highFivesGuys();

    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag2;

    std::cout << "\n--- Testing ScavTrap ---" << std::endl;
    ScavTrap scav1("ScavOne");
    scav1.attack("EnemyThree");
    scav1.guardGate();

    ScavTrap scav2(scav1);
    ScavTrap scav3;
    scav3 = scav1;

    std::cout << "\n--- Testing DiamondTrap ---"  << std::endl;
    DiamondTrap diamond1("DiamondOne");

    diamond1.takeDamage(0);
    diamond1.beRepaired(0);
    diamond1.attack("EnemyFour");
    diamond1.highFivesGuys();
    diamond1.guardGate(); 
    diamond1.whoAmI(); 

    DiamondTrap diamond2(diamond1);
    DiamondTrap diamond3;
    diamond3 = diamond2;

    std::cout << "\n--- End of Tests ---" << std::endl;
    return 0;
}
