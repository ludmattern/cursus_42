/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:51:09 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 19:20:23 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : _type("undefined")
{
    std::cout << "Animal created, it's " << _type << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << _type << " copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other) {
        _type = other._type;
    }
    std::cout << _type << " assigned" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "..." << std::endl;
}
