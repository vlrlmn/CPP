/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:12:53 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/09/30 19:26:31 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- Test 1: Default Constructor ---\n";
    ScavTrap scav1;

    std::cout << "\n--- Test 2: Parameterized Constructor ---\n";
    ScavTrap scav2("Scavy");

    std::cout << "\n--- Test 3: Copy Constructor ---\n";
    ScavTrap scav3(scav2);

    std::cout << "\n--- Test 4: Copy Assignment Operator ---\n";
    ScavTrap scav4;
    scav4 = scav1;

    std::cout << "\n--- Test 5: Attack Function ---\n";
    scav2.attack("enemy");

    std::cout << "\n--- Test 6: GuardGate Function ---\n";
    scav2.guardGate();

    std::cout << "\n--- End of Tests ---\n";
    return 0;
}
