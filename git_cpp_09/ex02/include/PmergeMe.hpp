/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:37:28 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/28 20:51:44 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <ctime>
#include <stdexcept>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(int argc, char** argv);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    void sortAndMeasure();

private:
    std::vector<int> parseArguments(int argc, char** argv);
    template <typename Container> double measureSortTime(Container& container);
    template <typename Container> void printContainer(const Container& container);
    template <typename Container> void mergeInsertSortImpl(Container& container);
    std::vector<int> input;
};

#endif
