/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:27:52 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/09 19:42:16 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _numOfContacts(0) {};

int PhoneBook::getNumOfContacts()
{
    return(_numOfContacts);
}

void PhoneBook::printContact(int index)
{
	Contact &userChoice = _contacts[index - 1];
	std::cout << "First name: " << userChoice.getFirstName() << std::endl;
	std::cout << "Last name: " << userChoice.getLastName() << std::endl;
	std::cout << "Nick name: " << userChoice.getNickName() << std::endl;
	std::cout << "Phone number: " << userChoice.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << userChoice.getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact(PhoneBook   &newBook)
{
    int index;

    if (newBook.getNumOfContacts() == 0)
    {
        std::cout << RED << BOLD << "No contacts in the book" << RESET << std::endl;
        return ;
    }
    newBook.printBook();
    while (true)
    {
        std::cout << BOLD << "Chose the index of a desired phone contact:" << RESET << std::endl;
        std::cin >> index;
        if (std::cin.fail() || index < 1 || index > _numOfContacts)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << RED << BOLD << "Invalid index!" << RESET << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            newBook.printContact(index);
            break ;
        }
    }

}

void PhoneBook::printBook()
{
    std::cout << BOLD << "_____________________________________________" << RESET << std::endl;
    std::cout << BOLD << "|Index     |First Name|Last Name |Nickname  |" << RESET << std::endl;
    std::cout << BOLD << "|___________________________________________|" << RESET << std::endl;
    for (int i = 0; i < _numOfContacts; i++)
    {
        std::cout << '|';
        std::cout << std::setw(10) << i + 1 << '|';
        std::cout << std::setw(10) << (_contacts[i].getFirstName().length() > 9 ? _contacts[i].getFirstName().substr(0, 9) + "." : _contacts[i].getFirstName()) << '|';
        std::cout << std::setw(10) << (_contacts[i].getLastName().length() > 9 ? _contacts[i].getLastName().substr(0, 9) + "." : _contacts[i].getLastName()) << '|';
        std::cout << std::setw(10) << (_contacts[i].getNickName().length() > 9 ? _contacts[i].getNickName().substr(0, 9) + "." : _contacts[i].getNickName()) << '|' << std::endl;
    }
    std::cout << BOLD << "|___________________________________________|" << RESET << std::endl;
}

void	PhoneBook::addContact(Contact &newContact)
{ 
      static int oldestContactIndex = 0;
    if (_numOfContacts < 8)
    {
        _contacts[_numOfContacts] = newContact;
        _numOfContacts++;
    } else 
    {
        _contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
}

void PhoneBook::createContact()
{
    
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << BOLD << BLUE << "Please put the following information:" << RESET << std::endl;
    std::cout << BOLD << WHITE <<"Enter first name:" << RESET << std::endl;
    std::getline(std::cin, firstName);
    std::cout << BOLD << WHITE "Enter last name:" << RESET << std::endl;
    std::getline(std::cin, lastName);
    std::cout << BOLD << WHITE "Enter nick name:" << RESET << std::endl;
    std::getline(std::cin, nickName);
    std::cout << BOLD << WHITE "Enter phone number" << RESET << std::endl;
    std::getline(std::cin, phoneNumber);
    std::cout <<  BOLD << WHITE"Enter darkest secret" << RESET << std::endl;
    std::getline(std::cin, darkestSecret);
    
    Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    addContact(newContact);
    std::cout << BLUE << BOLD << "New contact created!" << RESET << std::endl;
}