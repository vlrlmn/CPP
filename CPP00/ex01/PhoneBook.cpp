/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:27:52 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/09 21:18:38 by lomakinaval      ###   ########.fr       */
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
	std::cout << BOLD << "     First name:       " << userChoice.getFirstName() << RESET << std::endl;
	std::cout << BOLD << "     Last name:        " << userChoice.getLastName() << RESET << std::endl;
	std::cout << BOLD << "     Nick name:        " << userChoice.getNickName() << RESET << std::endl;
	std::cout << BOLD << "     Phone number:     " << userChoice.getPhoneNumber() << RESET << std::endl;
	std::cout << BOLD << "     Darkest secret:   " << userChoice.getDarkestSecret() << RESET << std::endl;
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
        std::cout << BLUE << BOLD << "Chose the index of a desired phone contact:" << RESET << std::endl;
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

bool PhoneBook::isValidName(const std::string &str)
{
    if (str.empty())
        return (false);
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isalpha(str[i]))
            return (false);
    }
    return (true);
}

bool PhoneBook::isValidPhoneNumber(const std::string &str)
{
    if (str.empty())
        return (false);
    for (size_t i = 0; i < str.length(); i++)
    {
        if(!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool PhoneBook::isValidNonEmpty(const std::string &str) 
{
    return (!str.empty());
}

std::string PhoneBook::getInput(const std::string &prompt, bool (*validate)(const std::string &))
{
    std::string input;
    while(true)
    {
        std::cout << BOLD << prompt << RESET;
        std::getline(std::cin, input);
        if (validate(input))
            break ;
        else
            std::cout << RED << BOLD "Invalid input, Please try again" << RESET << std::endl;
    }
    return (input);
}

void PhoneBook::createContact()
{
    std::string firstName = getInput("Enter first name: ", PhoneBook::isValidName);
    std::string lastName = getInput("Enter last name: ", PhoneBook::isValidName);
    std::string nickName = getInput("Enter nick name: ", PhoneBook::isValidNonEmpty);
    std::string phoneNumber = getInput("Enter phone number: ", PhoneBook::isValidPhoneNumber);
    std::string darkestSecret = getInput("Enter darkest secret: ", PhoneBook::isValidNonEmpty);

    Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    addContact(newContact);
    std::cout << BLUE << BOLD << "New contact created!" << RESET << std::endl;
}