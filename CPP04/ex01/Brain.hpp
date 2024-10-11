/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:39:25 by vlomakin          #+#    #+#             */
/*   Updated: 2024/10/11 12:38:29 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain 
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &original);
		const Brain & operator=(const Brain &original);
		~Brain();
};

#endif