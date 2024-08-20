/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:44:16 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/06 12:03:25 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class   Fixed
{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        void    setRawBits(int const raw);
        int     getRawBits(void) const;
        int     toInt(void) const;
        float   toFloat(void) const;

        bool    operator>(const Fixed &other) const;
        bool    operator<(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;

        Fixed   operator+(const Fixed &other) const;
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;

        Fixed   &operator++(void);
        Fixed   &operator--(void);
        Fixed   operator++(int);
        Fixed   operator--(int);

        static          Fixed &min(Fixed &a, Fixed &b);
        static const    Fixed &min(const Fixed &a, const Fixed &b);
        static          Fixed &max(Fixed &a, Fixed &b);
        static const    Fixed &max(const Fixed &a, const Fixed &b);

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif