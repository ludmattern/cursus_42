/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/27 16:36:40 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        int result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}