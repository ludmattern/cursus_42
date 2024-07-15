/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:45:06 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/31 17:27:56 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
    name(name),
    weapon(NULL)
{}

HumanB::~HumanB()
{}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << name
            << " attacks with his " << weapon->getType()
            << std::endl;
    else
        std::cout << name
            << " attacks with his bare hands"
            << std::endl;
}