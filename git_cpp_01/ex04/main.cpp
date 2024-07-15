/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:44:14 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/05 16:47:52 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceString(std::string &str, const std::string &s1, const std::string &s2)
{
    size_t pos = 0;
    while ((pos = str.find(s1, pos)) != std::string::npos)
    {
        str.erase(pos, s1.length());
        str.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argc, char **argv)
{
    std::string fileContent;
    std::string line;
    std::string filename;

    if (argc != 4)
        return (std::cerr << "Usage: " << argv[0] << " filename s1 s2" << std::endl, 1);

    if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty())
    if (!argv[1] || !argv[2] || !argv[3])
        return (std::cerr << "Error: Empty arguments" << std::endl, 1);

    filename = argv[1];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        return (std::cerr << "Error: Could not open file " << filename << std::endl, 1);

    while (std::getline(inputFile, line))
        fileContent += line + '\n';

    inputFile.close();

    if (fileContent.empty())
        return (std::cerr << "Error: The file is empty" << std::endl, 1);
    else
        fileContent.erase(fileContent.size() - 1);

    replaceString(fileContent, argv[2], argv[3]);

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open())
        return (std::cerr << "Error: Could not create file " << filename << ".replace" << std::endl, 1);

    outputFile << fileContent;
    outputFile.close();

    return (0);
}
