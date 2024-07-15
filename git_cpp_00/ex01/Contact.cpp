/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:36:41 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/28 17:15:45 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() :
    first_name(""),
    last_name(""),
    nickname(""),
    phone_number(""),
    darkest_secret("")
{}

void Contact::setField(Field field, const std::string& value)
{
    switch (field)
    {
        case FIRST_NAME:
            first_name = value;
            break;
        case LAST_NAME:
            last_name = value;
            break;
        case NICKNAME:
            nickname = value;
            break;
        case PHONE_NUMBER:
            phone_number = value;
            break;
        case DARKEST_SECRET:
            darkest_secret = value;
            break;
    }
}

std::string Contact::getField(Field field) const
{
    switch (field)
    {
        case FIRST_NAME:
            return (first_name);
        case LAST_NAME:
            return (last_name);
        case NICKNAME:
            return (nickname);
        case PHONE_NUMBER:
            return (phone_number);
        case DARKEST_SECRET:
            return (darkest_secret);
        default:
            return "";
    }
}
