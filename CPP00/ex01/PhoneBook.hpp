/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:33:52 by vlomakin          #+#    #+#             */
/*   Updated: 2024/08/09 18:21:28 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
};

#endif
