/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:59:56 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/01 15:39:09 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

char toUpperChar(const char c)
{
	return (static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
}

void convertToUpperAndPrint(const char* str)
{
	for (size_t j = 0; str[j] != '\0'; ++j)
		std::cout << toUpperChar(str[j]);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i)
		convertToUpperAndPrint(argv[i]);
	std::cout << std::endl;
	return (0);
}
