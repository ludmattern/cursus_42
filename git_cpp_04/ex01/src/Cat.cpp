/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:51:09 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 19:20:45 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
    _type = "Cat";
    std::cout << "Animal created, it's a " << _type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
    _type = other._type;
    std::cout << "Cat copied, it's a " << _type << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other) {
        Animal::operator=(other);
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Cat assigned, it's a " << _type << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
