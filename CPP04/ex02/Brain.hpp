/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:39:25 by vlomakin          #+#    #+#             */
/*   Updated: 2024/10/11 19:11:08 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &original);
		Brain & operator=(const Brain &original);
		virtual ~Brain();
};

#endif