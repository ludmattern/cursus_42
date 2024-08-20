/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:31:59 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/01 21:57:07 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap claptrap1("CT1");
    ClapTrap claptrap2("CT2");

    claptrap1.attack("CT2");
    claptrap2.takeDamage(0);
    claptrap2.beRepaired(5);

    ScavTrap scavtrap1("ST1");
    ScavTrap scavtrap2("ST2");

    scavtrap1.attack("CT1");
    scavtrap2.takeDamage(20);
    scavtrap2.beRepaired(10);
    scavtrap2.guardGate();

    return (0);
}
