/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:13:15 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 13:56:33 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(bool baseClass) : _type("undefined")
{
    if (baseClass) {
    std::cout << "WrongAnimal created, it's " << _type << std::endl;
    }
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type), _isBaseClass(other._isBaseClass) {
    std::cout << _type << " copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other) {
        _type = other._type;
        _isBaseClass = other._isBaseClass;
    }
    std::cout << _type << " assigned" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destroyed" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}
