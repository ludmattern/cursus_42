/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+    */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:45:23 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/28 12:35:44 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cerrno>
#include <limits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv)
{
    input = parseArguments(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe& other) : input(other.input) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other) input = other.input;
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::parseArguments(int argc, char** argv)
{
    std::vector<int>    vec;
    char*               endptr;
    long                num;
    int                 i;

    for (i = 1; i < argc; ++i)
    {
        errno = 0;
        num = std::strtol(argv[i], &endptr, 10);
        
        if (*endptr != '\0')
            throw std::runtime_error("Invalid input: Non-integer value");
        if (errno == ERANGE || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
            throw std::runtime_error("Invalid input: Integer overflow");
        if (num <= 0)
            throw std::runtime_error("Invalid input: Non-positive integer");

        vec.push_back(static_cast<int>(num));
    }
    return vec;
}

void PmergeMe::sortAndMeasure()
{
    std::vector<int>    vec;
    double              vectorTime, listTime, timeDifference;
    std::list<int>      lst(input.begin(), input.end());

    vec = input;
    vectorTime = measureSortTime(vec);
    listTime = measureSortTime(lst);

    std::cout << "Before: ";
    printContainer(input);

    std::cout << "After: ";
    printContainer(vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vectorTime << " µs" << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << listTime << " µs" << std::endl;

    timeDifference = vectorTime - listTime;
    std::cout << "Difference in time: " << timeDifference << " µs (positive means vector was slower, negative means list was slower)" << std::endl;
}

template <typename Container> double PmergeMe::measureSortTime(Container& container)
{
    std::clock_t    start, end;
    double          delta;

    start = std::clock();
    mergeInsertSortImpl(container);
    end = std::clock();
    delta = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    return delta;
}

template <typename Container> void PmergeMe::printContainer(const Container& container)
{
    typename Container::const_iterator it;

    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}

template <typename T> void PmergeMe::mergeInsertSortImpl(T& container)
{
    typename T::iterator    mid, leftIt, rightIt;

    if (container.size() <= 1)
        return;

    mid = container.begin();
    std::advance(mid, container.size() / 2);
    T left(container.begin(), mid);
    T right(mid, container.end());

    mergeInsertSortImpl(left);
    mergeInsertSortImpl(right);

    container.clear();
    leftIt = left.begin();
    rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end())
    {
        if (*leftIt < *rightIt)
            container.push_back(*leftIt++);
        else
            container.push_back(*rightIt++);
    }

    while (leftIt != left.end())
        container.push_back(*leftIt++);

    while (rightIt != right.end())
        container.push_back(*rightIt++);
}
