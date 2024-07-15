/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:45:23 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 13:53:07 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    for (int i = 0; i < 4; ++i) {
        if (other._materias[i]) {
            _materias[i] = other._materias[i]->clone();
        } else {
            _materias[i] = NULL;
        }
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _materias[i];
            if (other._materias[i]) {
                _materias[i] = other._materias[i]->clone();
            } else {
                _materias[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i) {
        delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i) {
        if (!_materias[i]) {
            _materias[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & _type)
{
    for (int i = 0; i < 4; ++i) {
        if (_materias[i] && _materias[i]->getType() == _type) {
            return _materias[i]->clone();
        }
    }
    return NULL;
}
