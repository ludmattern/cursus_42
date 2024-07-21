/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:45:23 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/20 20:43:43 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cerrno>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::LiteralType ScalarConverter::getLiteralType(const std::string& literal) {
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff")
        return NAN_INF;
	else if (isChar(literal))
        return CHAR;
	else if (isInt(literal))
        return INT;
	else if (isFloat(literal))
        return FLOAT;
	else if (isDouble(literal))
        return DOUBLE;
	else
        return INVALID;
}

void ScalarConverter::convert(const std::string& literal) {
    bool charConv = false, intConv = false, floatConv = false, doubleConv = false;
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    long longVal = 0;
    float floatVal = 0.0f;
    double doubleVal = 0.0;

    switch (getLiteralType(literal)) {
        case CHAR:
            c = literal[1];
            charConv = true;
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            intConv = floatConv = doubleConv = true;
            break;
        
        case INT:
            errno = 0;
            longVal = std::strtol(literal.c_str(), NULL, 10);
            if (errno == ERANGE || longVal < std::numeric_limits<int>::min() || longVal > std::numeric_limits<int>::max())
                intConv = false;
			else {
                i = static_cast<int>(longVal);
                intConv = true;
                if (i >= 32 && i <= 126) {
                    c = static_cast<char>(i);
                    charConv = true;
                }
                f = static_cast<float>(i);
                d = static_cast<double>(i);
                floatConv = doubleConv = true;
            }
            break;
        
        case FLOAT:
            floatVal = std::strtof(literal.c_str(), NULL);
            f = floatVal;
            floatConv = true;
            if (f >= 32 && f <= 126) {
                c = static_cast<char>(f);
                charConv = true;
            }
            if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max()) {
                i = static_cast<int>(f);  // Explicit cast: float to int
                intConv = true;
            }
            d = static_cast<double>(f);
            doubleConv = true;
            break;
        
        case DOUBLE:
            doubleVal = std::strtod(literal.c_str(), NULL);
            d = doubleVal;
            doubleConv = true;
            if (d >= 32 && d <= 126) {
                c = static_cast<char>(d);
                charConv = true;
            }
            if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()) {
                i = static_cast<int>(d);  // Explicit cast: double to int
                intConv = true;
            }
            if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()) {
                f = static_cast<float>(d);  // Explicit cast: double to float
                floatConv = true;
            }
            break;
        
        case NAN_INF:
            if (literal == "nan" || literal == "nanf") {
                f = std::numeric_limits<float>::quiet_NaN();
                d = std::numeric_limits<double>::quiet_NaN();
            } else if (literal == "+inf" || literal == "+inff") {
                f = std::numeric_limits<float>::infinity();
                d = std::numeric_limits<double>::infinity();
            } else if (literal == "-inf" || literal == "-inff") {
                f = -std::numeric_limits<float>::infinity();
                d = -std::numeric_limits<double>::infinity();
            }
            floatConv = doubleConv = true;
            charConv = intConv = false;
            break;
        
        case INVALID:
        default:
            break;
    }

    printChar(charConv, c);
    printInt(intConv, i);
    printFloat(floatConv, f);
    printDouble(doubleConv, d);
}

void ScalarConverter::printChar(bool success, char c)
{
    if (success)
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: impossible\n";
}

void ScalarConverter::printInt(bool success, int i)
{
    if (success)
        std::cout << "int: " << i << "\n";
    else
        std::cout << "int: impossible\n";
}

void ScalarConverter::printFloat(bool success, float f)
{
    if (success)
        std::cout << "float: " << f << "f\n";
    else
        std::cout << "float: impossible\n";
}

void ScalarConverter::printDouble(bool success, double d)
{
    if (success)
        std::cout << "double: " << d << "\n";
    else
        std::cout << "double: impossible\n";
}

bool ScalarConverter::isChar(const std::string& literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && std::isprint(literal[1]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
    char* end = NULL;
    errno = 0;
    long val = std::strtol(literal.c_str(), &end, 10);
    if (errno != 0 || *end != '\0' || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        return false;
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    char* end = NULL;
    errno = 0;
    float val = std::strtof(literal.c_str(), &end);
    (void)val;
    if (errno != 0 || *end != 'f' || *(end + 1) != '\0')
        return false;
    return true;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    char* end = NULL;
    errno = 0;
    double val = std::strtod(literal.c_str(), &end);
    (void)val;
    if (errno != 0 || *end != '\0')
        return false;
    return true;
}
