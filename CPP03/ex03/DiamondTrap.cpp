/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:50:01 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/02 18:27:17 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    name = "None";
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string _name) : ClapTrap(_name + "_clap_name"), name(_name)
{
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap parametrized constructor for " << this->name << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor is created" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
    ClapTrap::operator=(other);
    FragTrap::operator=(other);
    ScavTrap::operator=(other);
    
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
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
    if (target.empty())
    {
        std::cout << "Incorrect target" << std::endl;
        return ;
    }
    ScavTrap::attack(target);
}