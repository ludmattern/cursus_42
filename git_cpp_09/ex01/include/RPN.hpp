/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:37:28 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/27 16:58:28 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluate(const std::string& expression) const;

private:
    bool isOperator(char c) const;
    int applyOperation(char op, int a, int b) const;
    bool isValidNumber(const std::string& token) const;
};

#endif
