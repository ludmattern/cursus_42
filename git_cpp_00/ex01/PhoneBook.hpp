/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:56:49 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/28 16:39:43 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
    public:
        PhoneBook();

        void addContact(const Contact& contact);
        void searchContacts() const;

    private:
        static const int MAX_CONTACTS = 8;
        Contact contacts[MAX_CONTACTS];
        int currentContactIndex;
        int totalContacts;

        void displayField(const std::string& field) const;
};

#endif