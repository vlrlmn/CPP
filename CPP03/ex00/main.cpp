/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:12:53 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/11 18:58:43 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1("Clappy");
    ClapTrap claptrap2("Trappy");

    std::cout << "\n--- Test Attack ---" << std::endl;
    claptrap1.attack("Trappy");
    claptrap2.attack("Clappy");

    std::cout << "\n--- Test Take Damage ---" << std::endl;
    claptrap1.takeDamage(5);
    claptrap2.takeDamage(3);

    std::cout << "\n--- Test Repair ---" << std::endl;
    claptrap1.beRepaired(4);
    claptrap2.beRepaired(5);

    std::cout << "\n--- Test Attack Without Energy ---" << std::endl;
    for (int i = 0; i < 10; ++i) {
        claptrap2.attack("Clappy");
    }
    claptrap2.attack("Clappy");

    std::cout << "\n--- Test Repair Without Energy ---" << std::endl;
    claptrap2.beRepaired(3);

    std::cout << "\n--- Test Copy Constructor and Assignment Operator ---" << std::endl;
    ClapTrap claptrap3 = claptrap1;

    std::cout << "\n--- End of Tests ---" << std::endl;
}