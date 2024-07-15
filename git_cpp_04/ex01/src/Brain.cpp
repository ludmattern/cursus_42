/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:14:03 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 16:28:32 by lmattern         ###   ########.fr       */
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
    if (this != &other) 
    {
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
