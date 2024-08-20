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
#include <iterator>
#include <vector>
#include <list>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv)
{
    std::clock_t start = std::clock();
    _inputv = parseArgumentsToVector(argc, argv);
    std::clock_t end = std::clock();
    _vectorCopyTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    start = std::clock();
    _inputl = parseArgumentsToList(argc, argv);
    end = std::clock();
    _listCopyTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

PmergeMe::PmergeMe(const PmergeMe& other) : _inputv(other._inputv) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
        _inputv = other._inputv;
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::parseArgumentsToVector(int argc, char** argv)
{
    std::vector<int> vec;
    char* endptr;
    long num;

    for (int i = 1; i < argc; ++i)
    {
        errno = 0;
        if (!argv[i][0])
            throw std::runtime_error("Invalid input: Empty value");
        num = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0')
            throw std::runtime_error("Invalid input: Non-integer value");
        if (errno == ERANGE || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
            throw std::runtime_error("Invalid input: Integer overflow");
        if (num < 0)
            throw std::runtime_error("Invalid input: Non-positive integer");

        vec.push_back(static_cast<int>(num));
    }
    return vec;
}

std::list<int> PmergeMe::parseArgumentsToList(int argc, char** argv)
{
    std::list<int> lst;
    char* endptr;
    long num;

    for (int i = 1; i < argc; ++i)
    {
        errno = 0;
        if (!argv[i][0])
            throw std::runtime_error("Invalid input: Empty value");
        num = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0')
            throw std::runtime_error("Invalid input: Non-integer value");
        if (errno == ERANGE || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
            throw std::runtime_error("Invalid input: Integer overflow");
        if (num < 0)
            throw std::runtime_error("Invalid input: Non-positive integer");

        lst.push_back(static_cast<int>(num));
    }
    return lst;
}
	

void PmergeMe::sortAndMeasure()
{
    std::vector<int> vec = _inputv;
    std::list<int> lst = _inputl;

    double vectorSortTime = measureSortTimeVector(vec);
    double listSortTime = measureSortTimeList(lst);

    std::cout << "Before: ";
    printVector(_inputv);

    std::cout << "After: ";
    printVector(vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector :";
    std::cout << " Data managment -> " << _vectorCopyTime << " µs; "; 
    std::cout << "  Sorting -> " << vectorSortTime << " µs" << std::endl;

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list   :";
    std::cout << " Data managment -> " << _listCopyTime << " µs; "; 
    std::cout << "  Sorting -> " << listSortTime << " µs" << std::endl;
}

double PmergeMe::measureSortTimeVector(std::vector<int>& vec)
{
    std::clock_t start = std::clock();
    fordJohnsonSortVector(vec);
    std::clock_t end = std::clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

double PmergeMe::measureSortTimeList(std::list<int>& lst)
{
    std::clock_t start = std::clock();
    fordJohnsonSortList(lst);
    std::clock_t end = std::clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::printVector(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<int> pairs, leftovers;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
        pairs.push_back(vec[i + 1]);
        leftovers.push_back(vec[i]);
    }

    if (vec.size() % 2 != 0)
        leftovers.push_back(vec.back());

    fordJohnsonSortVector(pairs);

    for (size_t i = 0; i < leftovers.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(pairs.begin(), pairs.end(), leftovers[i]);
        pairs.insert(pos, leftovers[i]);
    }

    vec.swap(pairs);
}

void PmergeMe::fordJohnsonSortList(std::list<int>& lst)
{
    if (lst.size() <= 1)
        return;

    std::list<int> pairs, leftovers;

    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); )
    {
        std::list<int>::iterator next = it;
        ++next;
        if (next != lst.end())
        {
            if (*it > *next)
                std::iter_swap(it, next);
            pairs.push_back(*next);
            leftovers.push_back(*it);
            it = next;
            ++it;
        }
        else
        {
            leftovers.push_back(*it);
            ++it;
        }
    }

    fordJohnsonSortList(pairs);

    for (std::list<int>::iterator it = leftovers.begin(); it != leftovers.end(); ++it)
    {
        std::list<int>::iterator pos = std::lower_bound(pairs.begin(), pairs.end(), *it);
        pairs.insert(pos, *it);
    }

    lst.swap(pairs);
}

/*
Example:

Original sequence: [7, 3, 9, 2, 5, 1]

Form pairs: (7, 3), (9, 2), (5, 1)

Pairs after local sorting: (3, 7), (2, 9), (1, 5)

Dominants: [7, 9, 5]
Subordinates: [3, 2, 1]

Recursive Sorting of Dominants
Sorted Dominants: [5, 7, 9]

Inserting Subordinates into Sorted Dominants
Subordinates: [3, 2, 1]

Insert 3 into [5, 7, 9] → [3, 5, 7, 9]
Insert 2 into [3, 5, 7, 9] → [2, 3, 5, 7, 9]
Insert 1 into [2, 3, 5, 7, 9] → [1, 2, 3, 5, 7, 9]
*/