/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/08/14 19:17:25 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No input provided" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe    pmerge(argc, argv);
        pmerge.sortAndMeasure();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}