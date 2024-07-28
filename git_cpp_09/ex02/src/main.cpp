/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/27 18:04:58 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    clock_t start = clock();
    try {
        for (size_t i = 1; i < static_cast<size_t>(argc); ++i) {
            int num = std::atoi(argv[i]);
            if (num <= 0) {
                throw std::runtime_error("Invalid input: Non-positive integer");
            }
            vec.push_back(num);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    mergeInsertSort(vec);
    clock_t end = clock();
    double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    try {
        for (size_t i = 1; i < static_cast<size_t>(argc); ++i) {
            int num = std::atoi(argv[i]);
            if (num <= 0) {
                throw std::runtime_error("Invalid input: Non-positive integer");
            }
            lst.push_back(num);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    mergeInsertSort(lst);
    end = clock();
    double listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Before: ";
    for (size_t i = 1; i < static_cast<size_t>(argc); ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " 
              << vectorTime << " µs" << std::endl;

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " 
              << listTime << " µs" << std::endl;

    double timeDifference = vectorTime - listTime;
    std::cout << "Difference in time: " << timeDifference << " µs (positive means vector was faster, negative means list was faster)" << std::endl;

    return 0;
}
