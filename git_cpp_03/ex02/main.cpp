/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:31:59 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/01 22:02:11 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap claptrap1("CT1");
    ScavTrap scavtrap1("ST1");
    FragTrap fragtrap1("FT1");
    fragtrap1.highFivesGuys();

    return (0);
}
