/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:45:30 by vlomakin          #+#    #+#             */
/*   Updated: 2024/10/14 16:47:04 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &original)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = original;
}

Brain & Brain::operator=(const Brain &original)
{
	*this = original;
	std::cout << "Brain copy assignment constructor called" << std::endl;
	if (this != &original)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = original.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}