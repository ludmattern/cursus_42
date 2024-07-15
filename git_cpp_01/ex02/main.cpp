/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:48:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/05 16:37:05 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "memory address of the string variable : " << &str << std::endl;
    std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;

    std::cout << "The value of the string variable : " << str << std::endl;
    std::cout << "The value value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value value pointed to by stringREF : " << stringREF << std::endl;
    return (0);
}
