/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:12:53 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/12 17:07:21 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- Test 1: Default Constructor ---" << std::endl;
    ScavTrap scav1;

    std::cout << "\n--- Test 2: Parameterized Constructor ---" << std::endl;
    ScavTrap scav2("Scavy");

    std::cout << "\n--- Test 3: Copy Constructor ---" << std::endl;
    ScavTrap scav3(scav2);

    std::cout << "\n--- Test 4: Copy Assignment Operator ---" << std::endl;
    ScavTrap scav4;
    scav4 = scav1;

    std::cout << "\n--- Test 5: Attack Function ---" << std::endl;
    scav2.attack("enemy");

    std::cout << "\n--- Test 6: GuardGate Function ---" << std::endl;
    scav2.guardGate();

    std::cout << "\n--- End of Tests ---" << std::endl;
    return 0;
}
