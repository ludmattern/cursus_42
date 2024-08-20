/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:19:40 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:31 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed sign(const Point &p1, const Point &p2, const Point &p3)
{
    return Fixed(roundf((p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) - 
                        (p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat())));
}

bool bsp(const Point &A, const Point &B, const Point &C, const Point &P)
{
    Fixed d1 = sign(P, A, B);
    Fixed d2 = sign(P, B, C);
    Fixed d3 = sign(P, C, A);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}
