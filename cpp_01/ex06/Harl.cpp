/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:45:06 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/05 17:36:05 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout   << "[ DEBUG ]"
                << std::endl
                << "I love having extra bacon for my 7XL-double-cheese-triple"
                << "-pickle-special-ketchup burger. I really do!"
                << std::endl
                << std::endl;
}

void Harl::info(void)
{
    std::cout   << "[ INFO ]"
                << std::endl
                << "I cannot believe adding extra bacon costs more money."
                << std::endl
                << "You didn’t put enough bacon in my burger! If you did, I "
                << "wouldn’t be asking for more!"
                << std::endl
                << std::endl;
}

void Harl::warning(void)
{
   std::cout    << "[ WARNING ]"
                << std::endl
                << "I think I deserve to have some extra bacon for free."
                << std::endl
                << "I’ve been coming for years whereas you started working here"
                << " since last month."
                << std::endl
                << std::endl;
}

void Harl::error(void)
{
    std::cout   << "[ ERROR ]"
                << std::endl
                << "This is unacceptable! I want to speak to the manager now."
                << std::endl << std::endl;
}

void Harl::filterMessages(int level)
{
    switch (level)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
            std::cout
            << "[ Probably complaining about insignificant problems ]"
            << std::endl;
            break;
    }
}

int Harl::hashString(const std::string& str)
{
    int hash = 0;
    for (size_t i = 0; i < str.length(); i++)
        hash += str[i];
    return hash;
}

void Harl::complain(std::string level)
{
    switch (hashString(level))
    {
        case 359:
            this->filterMessages(0);
            break;
        case 300:
            this->filterMessages(1);
            break;
        case 534:
            this->filterMessages(2);
            break;
        case 394:
            this->filterMessages(3);
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}