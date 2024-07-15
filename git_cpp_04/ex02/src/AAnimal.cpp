/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:51:09 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 19:41:38 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : _type("undefined")
{
    std::cout << "Animal created, it's " << _type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
    std::cout << _type << " copied" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other) {
        _type = other._type;
    }
    std::cout << _type << " assigned" << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destroyed" << std::endl;
}

std::string AAnimal::getType() const
{
    return _type;
}

void AAnimal::makeSound() const
{
    std::cout << "..." << std::endl;
}
