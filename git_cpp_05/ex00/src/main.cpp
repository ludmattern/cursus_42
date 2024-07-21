/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/17 10:11:23 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;

        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;

        Bureaucrat b3("Charlie", 0);
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b4("Dave", 151);
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
