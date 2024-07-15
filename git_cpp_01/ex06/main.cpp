/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:44:14 by lmattern          #+#    #+#             */
/*   Updated: 2024/05/31 19:14:55 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr   << "Usage: " << argv[0]
                            << " <log level>" << std::endl, 1);

    if(std::string(argv[1]).empty())
        return (std::cerr   << "Usage: " << argv[0]
                            << " <log level>" << std::endl, 1);

    Harl harl;
    harl.complain(argv[1]);

    return (0);
}