/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:44:16 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/31 20:18:10 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{}

Fixed::Fixed(const int value)
{
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->_fixedPointValue > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_fixedPointValue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_fixedPointValue >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_fixedPointValue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_fixedPointValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_fixedPointValue != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue * other.getRawBits()) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other.getRawBits());
    return result;
}

Fixed &Fixed::operator++()
{
    ++this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++this->_fixedPointValue;
    return temp;
}

Fixed &Fixed::operator--()
{
    --this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --this->_fixedPointValue;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
