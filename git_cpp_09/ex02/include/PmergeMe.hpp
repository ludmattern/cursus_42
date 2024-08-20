/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:37:28 by lmattern          #+#    #+#             */
/*   Updated: 2024/08/14 17:56:19 by lmattern         ###   ########.fr       */
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
private:
    std::vector<int> parseArgumentsToVector(int argc, char** argv);
    std::list<int> parseArgumentsToList(int argc, char** argv);
    double measureSortTimeVector(std::vector<int>& vec);
    double measureSortTimeList(std::list<int>& lst);
    void printVector(const std::vector<int>& vec);
    void fordJohnsonSortVector(std::vector<int>& vec);
    void fordJohnsonSortList(std::list<int>& lst);
    std::vector<int> _inputv;
    std::list<int> _inputl;
    double _vectorCopyTime;
    double _listCopyTime;

public:
    PmergeMe();
    PmergeMe(int argc, char** argv);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    void sortAndMeasure();

};

#endif
