/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:30:55 by vlomakin          #+#    #+#             */
/*   Updated: 2024/08/07 15:01:00 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Contact
{
	private:
			std::string _firstName;
			std::string _lastName;
			std::string _nickName;
			std::string _phoneNumber;
			std::string _dark_secret;

	public:
		Contact();
		~Contact(void);
		Contact();
		void setFirstName(void);
		void setLastName(void);
		void setNickName(void);
		void setPhoneNumber(void);
		void setDarkestSecret(void);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
		void printContact(void);
};

#endif