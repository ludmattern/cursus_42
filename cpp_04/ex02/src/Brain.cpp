/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:14:03 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 19:40:00 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() : _ideas(new std::string[_SIZE])
{
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain& other) :  _ideas(new std::string[_SIZE])
{
    for (int i = 0; i < _SIZE; ++i) {
        _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copied" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
 if (this != &other) {
        delete[] _ideas;
        _ideas = new std::string[_SIZE];
        for (int i = 0; i < _SIZE; ++i) {
            _ideas[i] = other._ideas[i];
        }
    }
    std::cout << "Brain assigned" << std::endl;
    return *this;
}

Brain::~Brain()
{
    delete[] _ideas;
    std::cout << "Brain destroyed" << std::endl;
}

void Brain::addIdea(const std::string& idea, int index)
{
    if (index >= 0 && index < _SIZE) {
        _ideas[index] = idea;
    }
}

void Brain::showIdeas() const
{
    for (int i = 0; i < _SIZE; ++i) {
        if (!_ideas[i].empty()) {
            std::cout << "Idea " << i + 1 << ": " << _ideas[i] << std::endl;
        }
    }
}