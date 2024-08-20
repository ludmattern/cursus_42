/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:51:09 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 19:18:34 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal() 
{
    _type = "Cat";
    std::cout << "Animal created, it's a " << _type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    _type = other._type;
    std::cout << "Cat copied, it's a " << _type << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other) {
        Animal::operator=(other);
        _type = other._type;
    }
    std::cout << "Cat assigned, it's a " << _type << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
