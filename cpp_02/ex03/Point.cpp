/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:12:35 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/06 13:09:42 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(const float x, const float y) : x(x), y(y)
{}

Point::Point(const Point &other) : x(other.x), y(other.y)
{}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const 
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}
