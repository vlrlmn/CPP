/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:00 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/12 18:55:39 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
    std::cout << "SCAV TRAP Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name, unsigned int hit, unsigned int energy, unsigned int attack) :
    ClapTrap(name, hit, energy, attack)
{
    this->energyPoints = energy;
    std::cout << "ScavTrap parametrized constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) 
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return(*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    ClapTrap::attack("ScavTrap", target);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}