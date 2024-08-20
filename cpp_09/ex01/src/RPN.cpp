/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:45:23 by lmattern          #+#    #+#             */
/*   Updated: 2024/08/14 18:14:29 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cctype>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperation(char op, int a, int b) const
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        default: throw std::runtime_error("Invalid operator");
    }
}

bool RPN::isValidNumber(const std::string& token) const
{
    if (token.length() == 1 && isdigit(token[0]))
        return true;

    if (token.length() == 2 && token[0] == '-' && token[1] >= '1' && token[1] <= '9')
        return true;

    return false;
}

int RPN::evaluate(const std::string& expression) const
{
    int                 a, b, result, number;
    std::stack<int>     stack;
    std::string         token;
    std::istringstream  tokens(expression);

    while (tokens >> token)
    {
        if (isOperator(token[0]) && token.length() == 1)
        {
            if (stack.size() < 2) throw std::runtime_error("Invalid expression");

            b = stack.top(); stack.pop();
            a = stack.top(); stack.pop();
            result = applyOperation(token[0], a, b);
            stack.push(result);
        }
        else if (isValidNumber(token))
        {
            number = atoi(token.c_str());
            stack.push(number);
        }
        else
            throw std::runtime_error("Invalid token");
    }

    if (stack.size() != 1) throw std::runtime_error("Invalid expression");
	
    return stack.top();
}