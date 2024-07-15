/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:51:09 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 19:43:01 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain())
{
    _type = "Cat";
    std::cout << "Animal created, it's a " << _type << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain))
{
    _type = other._type;
    std::cout << "Cat copied, it's a " << _type << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other) {
        AAnimal::operator=(other);
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

void Cat::addIdea(const std::string& idea, int index)
{
    _brain->addIdea(idea, index);
}

void Cat::showIdeas() const
{
    _brain->showIdeas();
}