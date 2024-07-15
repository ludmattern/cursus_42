/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:51:13 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 19:42:54 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain())
{
    _type = "Dog";
    std::cout << "Animal created, it's a " << _type << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain))
{
    _type = other._type;
    std::cout << "Dog copied, it's a " << _type << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other) {
        AAnimal::operator=(other);
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Dog assigned, it's a " << _type << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

void Dog::addIdea(const std::string& idea, int index)
{
    _brain->addIdea(idea, index);
}

void Dog::showIdeas() const
{
    _brain->showIdeas();
}