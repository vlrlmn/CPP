/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:20:44 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/08 17:30:28 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string _type);
		WrongCat(const WrongCat &original);
		WrongCat & operator=(const WrongCat &original);
		~WrongCat();

		void makeSound() const;
		
};
