/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:37:28 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/22 10:09:22 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    if (std::distance(begin, end) + _numbers.size() > _maxSize) {
        throw std::length_error("Span is full");
    }
    _numbers.insert(_numbers.end(), begin, end);
}

#endif
