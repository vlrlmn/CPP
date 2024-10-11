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

    std::cout << "\n--- Test Attack ---\n";
    claptrap1.attack("Trappy");
    claptrap2.attack("Clappy");

    std::cout << "\n--- Test Take Damage ---\n";
    claptrap1.takeDamage(5);
    claptrap2.takeDamage(3);

    std::cout << "\n--- Test Repair ---\n";
    claptrap1.beRepaired(4);
    claptrap2.beRepaired(5);

    std::cout << "\n--- Test Attack Without Energy ---\n";
    for (int i = 0; i < 10; ++i) {
        claptrap2.attack("Clappy");
    }
    claptrap2.attack("Clappy");

    std::cout << "\n--- Test Repair Without Energy ---\n";
    claptrap2.beRepaired(3);

    std::cout << "\n--- Test Copy Constructor and Assignment Operator ---\n";
    ClapTrap claptrap3 = claptrap1;
}