/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:13:42 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 15:01:32 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(false)
{
    _type = "WrongCat";
    _isBaseClass = false;
    std::cout << "WrongAnimal created, it's a " << _type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    _type = other._type;
    _isBaseClass = false;
    std::cout << "WrongCat copied, it's a " << _type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other) {
        WrongAnimal::operator=(other);
        _type = other._type;
        _isBaseClass = false;
    }
    std::cout << "WrongCat assigned, it's a " << _type << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}
