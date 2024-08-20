/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/23 11:38:16 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main() {
    // Basic test with MutantStack
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating through MutantStack elements:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Test copy constructor and assignment operator
    std::cout << "Testing copy constructor and assignment operator:" << std::endl;
    MutantStack<int> copyStack(mstack);
    MutantStack<int> assignStack;
    assignStack = mstack;

    std::cout << "Copy stack:" << std::endl;
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "Assign stack:" << std::endl;
    for (MutantStack<int>::iterator it = assignStack.begin(); it != assignStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Test with constant iterators
    std::cout << "Testing constant iterators:" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();

    while (cit != cite) {
        std::cout << *cit << std::endl;
        ++cit;
    }

    // Test with reverse iterators
    std::cout << "Testing reverse iterators:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // Test with constant reverse iterators
    std::cout << "Testing constant reverse iterators:" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();

    while (crit != crite) {
        std::cout << *crit << std::endl;
        ++crit;
    }

    // Test implicit conversion to std::stack
    std::stack<int> s(mstack);
    std::cout << "Top element of std::stack: " << s.top() << std::endl;

    return 0;
}
