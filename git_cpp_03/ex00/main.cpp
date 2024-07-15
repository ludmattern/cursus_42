/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:31:59 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/01 21:54:23 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap1("CT1");
    ClapTrap claptrap2("CT2");

    claptrap1.attack("CT2");
    claptrap2.takeDamage(100);
    claptrap2.beRepaired(5);

    ClapTrap claptrap3(claptrap1);
    claptrap3.attack("CT2");

    ClapTrap claptrap4 = claptrap2;
    claptrap4.beRepaired(3);

    return (0);
}
