/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:45:06 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/31 17:06:53 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon() : type("Bare hands")
{}

Weapon::Weapon(std::string type) : type(type)
{}

Weapon::~Weapon()
{}

const std::string &Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
}