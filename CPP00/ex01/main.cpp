/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:14:19 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/12 12:15:19 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void printWelcomeMessage(void)
{
    std::cout << std::endl;
    std::cout << BOLD << WHITE << "*************************************************" << RESET << std::endl;
    std::cout << BOLD << WHITE << "*" << GREEN <<    "     Welcome to the PhoneBook application!     " << WHITE << "*" << RESET << std::endl;
    std::cout << BOLD << WHITE << "*  Please enter one of the following commands:  *" << RESET << std::endl;
    std::cout << BOLD << WHITE << "*          ADD    - Add a new contact           *" << RESET << std::endl;
    std::cout << BOLD << WHITE << "*         SEARCH - Search for a contact         *" << RESET << std::endl;
    std::cout << BOLD << WHITE << "*         EXIT   - Exit the application         *" << RESET << std::endl;
    std::cout << BOLD << WHITE << "*************************************************" << RESET << std::endl;
}

int main()
{
    PhoneBook   newBook;
    std::string input;
    
    while(1)
    {
        printWelcomeMessage();
        if (!std::getline(std::cin, input))
			break ;
        if (input.compare("EXIT") == 0 || input.compare("exit") == 0)
        {
            std::cout << RED << BOLD << "This phonebook is being erased... Bye!" << RESET << std::endl;
            break ;
        }
        else if (input.compare("ADD") == 0 || input.compare("add") == 0)
            newBook.createContact();
        else if (input.compare("SEARCH") == 0 || input.compare("search") == 0)
            newBook.searchContact(newBook);
        else
            std::cout << RED << BOLD << "NO OPTION FOUND! Please read an instruction" << RESET << std::endl;
    }
}