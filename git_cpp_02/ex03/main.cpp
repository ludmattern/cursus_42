/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:48:53 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/06 13:35:22 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point A(0, 0);
    Point B(2, 0);
    Point C(0, 5);

    Point D(3.5f, 9);
    Point E(5.5f, 5);
    Point F(7.5f, 9);

    Point G(1.5f, 9);
    Point H(0, 8);
    Point I(0, 10);

    Point P(3, 5);
    Point P1(1, 2);
    Point P2(5.5f, 8);

    if (bsp(A, B, C, P))
        std::cout << "Le point P est à l'intérieur du triangle 1." << std::endl;
    else
        std::cout << "Le point P est à l'extérieur du triangle 1." << std::endl;
    if (bsp(D, E, F, P))
        std::cout << "Le point P est à l'intérieur du triangle 2." << std::endl;
    else
        std::cout << "Le point P est à l'extérieur du triangle 2." << std::endl;
    if (bsp(G, H, I, P))
        std::cout << "Le point P est à l'intérieur du triangle 3." << std::endl;
    else
        std::cout << "Le point P est à l'extérieur du triangle 3." << std::endl;

    if (bsp(A, B, C, P1))
        std::cout << "Le point P1 est à l'intérieur du triangle 1." << std::endl;
    else
        std::cout << "Le point P1 est à l'extérieur du triangle 1." << std::endl;
    if (bsp(D, E, F, P1))
        std::cout << "Le point P1 est à l'intérieur du triangle 2." << std::endl;
    else
        std::cout << "Le point P1 est à l'extérieur du triangle 2." << std::endl;
    if (bsp(G, H, I, P1))
        std::cout << "Le point P1 est à l'intérieur du triangle 3." << std::endl;
    else
        std::cout << "Le point P1 est à l'extérieur du triangle 3." << std::endl;

    if (bsp(A, B, C, P2))
        std::cout << "Le point P2 est à l'intérieur du triangle 1." << std::endl;
    else
        std::cout << "Le point P2 est à l'extérieur du triangle 1." << std::endl;
    if (bsp(D, E, F, P2))
        std::cout << "Le point P2 est à l'intérieur du triangle 2." << std::endl;
    else
        std::cout << "Le point P2 est à l'extérieur du triangle 2." << std::endl;
    if (bsp(G, H, I, P2))
        std::cout << "Le point P2 est à l'intérieur du triangle 3." << std::endl;
    else
        std::cout << "Le point P2 est à l'extérieur du triangle 3." << std::endl;

    return (0);
}

/*
10
^
|           D___________F 
|            \         /
|             \   P2  /
|              \     / <------------------- triangle 2
|               \   /
|                \ /
C        P        E
|\
| \
|  \
|   \ <------------------------------------ triangle 1
| P1 \                        G
|     \                      / \ <--------- triangle 3
A------B--------------------H---I>10
*/
