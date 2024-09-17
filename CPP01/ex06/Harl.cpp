/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:42:09 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/20 14:34:08 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
   void (Harl::*complaints[])(void) = 
   {    
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
   };

   std::string levels[] = 
   {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
   };

   for(int i = 0; i < 4; i++)
   {
        if (levels[i] == level)
        {
            (this->*complaints[i])();
            return ;
        }
   }
    std::cout << "UNKNOWN: " << level << std::endl;
}

void Harl::filter(std::string level)
{
    int levelIndex = -1;

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for(int i = 0; i < 4; i++)
    {
        if(levels[i] == level)
        {
            levelIndex = i;
            break ;
        }
    }

    switch(levelIndex)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}