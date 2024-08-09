/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:30:55 by vlomakin          #+#    #+#             */
/*   Updated: 2024/08/09 18:23:16 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() 
{
	_firstName = "";
	_lastName = "";
	_nickName = "";
	_phoneNumber = "";
	_darkestSecret = "";
};

Contact::Contact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSecret)
{
	_firstName = fName;
	_lastName = lName;
	_nickName = nName;
	_phoneNumber = pNumber;
	_darkestSecret = dSecret;
}

std::string Contact::getFirstName()
{
	return (_firstName);
}

std::string Contact::getLastName()
{
	return (_lastName);
}

std::string Contact::getNickName()
{
	return (_nickName);
}
std::string Contact::getPhoneNumber()
{
	return (_phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return (_darkestSecret);
}
void Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}
void Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}
void Contact::setNickName(std::string nickName)
{
	_nickName = nickName;
}
void Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}
