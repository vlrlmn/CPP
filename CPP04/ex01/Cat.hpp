/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:06:05 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/09 16:00:22 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* catBrain;
	public:
		Cat();
		Cat(const std::string _type);
		Cat(const Cat &original);
		Cat & operator=(const Cat &original);
		~Cat();

		void makeSound() const;
		
};

#endif