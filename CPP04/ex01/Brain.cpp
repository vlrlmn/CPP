/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:45:30 by vlomakin          #+#    #+#             */
/*   Updated: 2024/10/24 16:08:56 by lomakinaval      ###   ########.fr       */
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
	for (int i = 0; i < 100; i++)
		this->ideas[i] = original.ideas[i];
}

const Brain & Brain::operator=(const Brain &original)
{
	std::cout << "Brain copy assignment constructor called" << std::endl;
	if (this != &original)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = original.ideas[i];
	}
	return (*this);
}

std::string& Brain::getIdea(int index)
{
	if (index >= 0 && index <= 100)
	{
		if (ideas[index].empty())
		{
			std::cout << "This brain is empty!" << std::endl;
		}
		return (ideas[index]);
	}
	static std::string outOfBounds = "Index is out of bounds";
	return (outOfBounds);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}