/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:33:52 by vlomakin          #+#    #+#             */
/*   Updated: 2024/08/09 21:38:40 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _numOfContacts;

    public:
        PhoneBook();
        
        int getNumOfContacts();
        void createContact();
        void createContact(PhoneBook   &newBook);
        void addContact(Contact &newContact);
        void searchContact(PhoneBook   &newBook);
        void printBook();
        void printContact(int index);

    private:
        std::string getInput(const std::string &prompt, bool (*validate)(const std::string &));
        static bool isValidName(const std::string &str);
        static bool isValidPhoneNumber(const std::string &str);
        static bool isValidNonEmpty(const std::string &str);
};

#endif
