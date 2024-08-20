/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:12:21 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/06 13:10:03 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;

    private:
        const Fixed x;
        const Fixed y;
};

Fixed sign(const Point &p1, const Point &p2, const Point &p3);
bool bsp(const Point &A, const Point &B, const Point &C, const Point &P);

#endif
