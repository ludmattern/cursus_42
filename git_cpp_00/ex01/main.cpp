/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:47:31 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/01 17:17:31 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

void addContact(PhoneBook& phoneBook)
{
    Contact contact;
    std::string input;

    std::pair<Contact::Field, const char *> fields[] = {
        std::make_pair(Contact::FIRST_NAME, "Enter first name: "),
        std::make_pair(Contact::LAST_NAME, "Enter last name: "),
        std::make_pair(Contact::NICKNAME, "Enter nickname: "),
        std::make_pair(Contact::PHONE_NUMBER, "Enter phone number: "),
        std::make_pair(Contact::DARKEST_SECRET, "Enter darkest secret: ")
    };

    for (int i = 0; i < 5; ++i)
    {
        std::cout << fields[i].second;
        std::getline(std::cin, input);
        contact.setField(fields[i].first, input);
    }

    phoneBook.addContact(contact);
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
            addContact(phoneBook);
        else if (command == "SEARCH")
            phoneBook.searchContacts();
        else if (command == "EXIT")
            break ;
        else if (std::cin.eof())
            break ;
        else
            std::cout << "Invalid command." << std::endl;
    }
    return (0);
}
