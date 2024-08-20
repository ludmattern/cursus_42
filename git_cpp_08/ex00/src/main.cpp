/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/23 11:13:37 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        // Test with std::vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        
        std::vector<int>::iterator itVec = easyfind(vec, 3);
        std::cout << "Found element in vector: " << *itVec << std::endl;

        itVec = easyfind(vec, 6); // Throw an exception
        std::cout << "Found element in vector: " << *itVec << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception in vector: " << e.what() << std::endl;
    }

    try {
        // Test with std::list
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);
        
        std::list<int>::iterator itList = easyfind(lst, 3);
        std::cout << "Found element in list: " << *itList << std::endl;

        itList = easyfind(lst, 6); // Throw an exception
        std::cout << "Found element in list: " << *itList << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception in list: " << e.what() << std::endl;
    }

    return 0;
}
