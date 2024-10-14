/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:50:01 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/12 18:39:20 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    name = "Diamond";
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string _name) : 
    ClapTrap(_name + "_clap_name"),
    FragTrap(_name), ScavTrap(_name),
    name(_name)
{
    std::cout << "DiamondTrap points. HitPoints: " << this->hitPoints << ". EnergyPoints: " 
    << this->energyPoints << ". AttackDamage: " << this->attackDamage 
    << std::endl;

    std::cout << "DiamondTrap parametrized constructor for " << this->name << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
{
    std::cout << "DiamondTrap copy constructor is created" << std::endl;
    name = other.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
    ClapTrap::operator=(other);
    name = other.name;
    std::cout << "DiamondTrap copy assignment constructor" << this->name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "Name DiamondTrap: " << this->name << std::endl;
    std::cout << "Name ClapTrap: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target) 
{
    ScavTrap::attack(target);
}