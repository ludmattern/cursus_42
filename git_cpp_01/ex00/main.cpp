/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:48:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/31 15:50:34 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* heapZombie;

    heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    randomChump("StackZombie");
    return (0);
}
