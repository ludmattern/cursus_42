/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:44:14 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/05 17:30:48 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;

    std::cout << "[DEBUG]" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "[INFO]" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "[WARNING]" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "[ERROR]" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "[UNKNOWN]" << std::endl;
    harl.complain("UNKNOWN");
    std::cout << std::endl;

    return 0;
}