/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:45:23 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/27 17:41:44 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

template <typename T>
void mergeInsertSortImpl(T& container);

void mergeInsertSort(std::vector<int>& vec) {
    mergeInsertSortImpl(vec);
}

void mergeInsertSort(std::list<int>& lst) {
    mergeInsertSortImpl(lst);
}

template <typename T>
void mergeInsertSortImpl(T& container) {
    if (container.size() <= 1) {
        return;
    }

    typename T::iterator mid = container.begin();
    std::advance(mid, container.size() / 2);
    T left(container.begin(), mid);
    T right(mid, container.end());

    mergeInsertSortImpl(left);
    mergeInsertSortImpl(right);

    container.clear();
    typename T::iterator leftIt = left.begin();
    typename T::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            container.push_back(*leftIt);
            ++leftIt;
        } else {
            container.push_back(*rightIt);
            ++rightIt;
        }
    }

    while (leftIt != left.end()) {
        container.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != right.end()) {
        container.push_back(*rightIt);
        ++rightIt;
    }
}
