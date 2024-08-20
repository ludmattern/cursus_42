/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:37:40 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/22 09:07:35 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/iter.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

int main(void) {
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Array of integers: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "Array of characters: ";
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Array of doubles: ";
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    std::string stringArray[] = {"one", "two", "three", "four", "five"};
    std::cout << "Array of strings: ";
    iter(stringArray, 5, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
