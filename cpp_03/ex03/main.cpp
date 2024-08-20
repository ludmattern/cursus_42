/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:31:59 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/01 22:35:59 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

    FragTrap fragtrap1("FT1");
    FragTrap fragtrap2("FT2");

    fragtrap1.attack("CT1");
    fragtrap2.takeDamage(30);
    fragtrap2.beRepaired(20);
    fragtrap2.highFivesGuys();

    DiamondTrap diamondtrap1("DT1");
    diamondtrap1.attack("FT1");
    diamondtrap1.whoAmI();

    return (0);
}
