/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:48:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/31 16:18:24 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* horde = zombieHorde(5, "Quentin");
    for (int i = 0; i < 5; i++)
        horde[i].announce();
    delete[] horde;
    return 0;
}
