/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:48:19 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/31 15:48:21 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Quentin")
{};

Zombie::Zombie(std::string name) : name(name)
{};

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " vanished in a puff of smoke" << std::endl;
};

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
};

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
};