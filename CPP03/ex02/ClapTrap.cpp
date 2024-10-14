/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:12:50 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/14 15:23:32 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "ClapTrap";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string _name)
{
    if (!_name.empty())
        name = _name;
    else
        name = "ClapTrap";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "Prametrized constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" <<std::endl;
    if (this != &other)
    {
    	this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& className, const std::string& target)
{
    if (target.empty())
    {
        std::cout << "Target not valid" << std::endl;
        return ;
    }
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << className << " " << this->name << " attacks " 
        << target << ", causing " << this->attackDamage
        << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << className << " " << this->name << " is out of energy or hit points and cannot attack." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    attack("ClapTrap", target);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        this->hitPoints = this->hitPoints - amount;
        if (hitPoints < 0)
            hitPoints = 0;
        std::cout << "ClapTrap " << this->name 
        << " takes " << amount
         << " points of damage! Remaining hit points: " 
         << hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        this->hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << this->name 
        << " repairs itself, recovering " 
        << amount << " hit points! Remaining hit points: " 
        << this->hitPoints << ", energy points: " 
        << this->energyPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name 
        << " cannot repair itself due to lack of energy or being destroyed." 
        << std::endl;
    }
}