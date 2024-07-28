/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/28 20:44:24 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        int result;
        RPN rpn;

        result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}