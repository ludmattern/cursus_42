/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/22 11:17:50 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        try {
            sp.addNumber(42);
        } catch (const std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::vector<int> vec;
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);

        Span sp2 = Span(10);
        sp2.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
        
        std::vector<int> largeVec(10000);
        std::srand(std::time(0));
        std::generate(largeVec.begin(), largeVec.end(), std::rand);

        Span largeSpan(10000);
        largeSpan.addNumbers(largeVec.begin(), largeVec.end());
        std::cout << "Shortest span (largeSpan): " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span (largeSpan): " << largeSpan.longestSpan() << std::endl;
        
        Span sp3 = Span(1);
        sp3.addNumber(1);
        try {
            std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        try {
            std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
