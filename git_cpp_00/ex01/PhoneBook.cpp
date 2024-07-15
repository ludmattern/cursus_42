/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:32:19 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/03 17:03:15 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <cstdlib>

PhoneBook::PhoneBook() :
    currentContactIndex(0),
    totalContacts(0)
{}

void PhoneBook::addContact(const Contact& contact)
{
    contacts[currentContactIndex] = contact;
    currentContactIndex = (currentContactIndex + 1) % MAX_CONTACTS;
    if (totalContacts < MAX_CONTACTS)
        totalContacts++;
}

void PhoneBook::displayField(const std::string& field) const
{
    if (field.length() > 10)
        std::cout << std::setw(10) << field.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << field;
}

void PhoneBook::searchContacts() const
{
    if (totalContacts == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First name" << "|"
              << std::setw(10) << "Last name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < totalContacts; ++i)
    {
        std::cout << std::setw(10) << i << "|";
        displayField(contacts[i].getField(Contact::FIRST_NAME));
        std::cout << "|";
        displayField(contacts[i].getField(Contact::LAST_NAME));
        std::cout << "|";
        displayField(contacts[i].getField(Contact::NICKNAME));
        std::cout << std::endl;
    }

    std::cout << "Enter the index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);

    bool isValid = true;
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (!isdigit(input[i]))
        {
            isValid = false;
            break;
        }
    }

    if (!isValid) 
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int index = std::atoi(input.c_str());
    if (index >= 0 && index < totalContacts)
    {
        std::cout << "First name: " << contacts[index].getField(Contact::FIRST_NAME) << std::endl;
        std::cout << "Last name: " << contacts[index].getField(Contact::LAST_NAME) << std::endl;
        std::cout << "Nickname: " << contacts[index].getField(Contact::NICKNAME) << std::endl;
        std::cout << "Phone number: " << contacts[index].getField(Contact::PHONE_NUMBER) << std::endl;
        std::cout << "Darkest secret: " << contacts[index].getField(Contact::DARKEST_SECRET) << std::endl;
    }
    else 
        std::cout << "Invalid index." << std::endl;
}
