/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:37:40 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/23 08:39:41 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <iostream>

int main() {
    try {
        // Test default constructor
        Array<int> array1;
        std::cout << "array1 size: " << array1.size() << std::endl;

        // Test constructor with size parameter
        Array<int> array2(5);
        std::cout << "array2 size: " << array2.size() << std::endl;
        for (unsigned int i = 0; i < array2.size(); ++i) {
            std::cout << array2[i] << " ";
        }
        std::cout << std::endl;

        // Test assignment operator and copy constructor
        Array<int> array3(array2);
        std::cout << "array3 size: " << array3.size() << std::endl;
        for (unsigned int i = 0; i < array3.size(); ++i) {
            std::cout << array3[i] << " ";
        }
        std::cout << std::endl;

        array2[2] = 42;
        std::cout << "Modified array2[2]: " << array2[2] << std::endl;
        std::cout << "array3[2] after modifying array2: " << array3[2] << std::endl;

        // Test out of bounds access
        std::cout << "Accessing out of bounds index in array2: ";
        std::cout << array2[10] << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
