/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:45:23 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/28 20:43:59 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _btcData(other._btcData), _inputData(other._inputData) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _btcData = other._btcData;
        _inputData = other._inputData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
    double          value;
    std::string     line, date;
    std::ifstream   file(filename.c_str());

    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return false;
    }

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        if (std::getline(iss, date, ',') && (iss >> value))
            _btcData[trim(date)] = value;
    }
    return true;
}

bool BitcoinExchange::loadInput(const std::string &filename)
{
    bool            isFirstLine;
    size_t          separatorPos;
    std::string     line, trimmedLine, headerDate, headerValue, date, value_str;
    std::ifstream   file(filename.c_str());

    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return false;
    }

    isFirstLine = true;
    while (std::getline(file, line))
    {
        trimmedLine = trim(line);
        if (isFirstLine)
        {
            std::istringstream headerStream(trimmedLine);
            if (std::getline(headerStream, headerDate, '|') && std::getline(headerStream, headerValue))
            {
                if (trim(headerDate) == "date" && trim(headerValue) == "value")
                {
                    isFirstLine = false;
                    continue;
                }
            }
        }

        if (line.find_first_not_of("0123456789|-. \t\n\r\f\v") != std::string::npos)
        {
            _inputData.push_back(std::make_pair(line, "Error: bad input"));
            continue;
        }

        separatorPos = line.find('|');
        if (separatorPos == std::string::npos)
        {
            _inputData.push_back(std::make_pair(line, "Error: bad input"));
            continue;
        }

        date = trim(line.substr(0, separatorPos));
        value_str = trim(line.substr(separatorPos + 1));

        _inputData.push_back(std::make_pair(date, value_str));
    }
    return true;
}

void BitcoinExchange::evaluate() const
{
    double      value, btcValue;
    std::string closestDate;
    std::deque<std::pair<std::string, std::string> >::const_iterator    it;

    for (it = _inputData.begin(); it != _inputData.end(); ++it)
    {
        const std::string &date = it->first;
        const std::string &value_str = it->second;

        if (value_str == "Error: bad input")
        {
            std::cout << value_str << " => " << date << std::endl;
            continue;
        }

        if (!isValidDate(date)) continue;

        std::istringstream value_iss(value_str);
        if (!(value_iss >> value))
        {
            std::cout << "Error: bad input => " << date << " | " << value_str << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        } else if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        closestDate = findClosestDate(date);
        if (!closestDate.empty())
        {
            btcValue = _btcData.find(closestDate)->second;
            std::cout << date << " => " << value << " = " << value * btcValue << std::endl;
        }
        else
            std::cout << "Error: no matching date found for " << date << std::endl;
    }
}

std::string BitcoinExchange::findClosestDate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _btcData.lower_bound(date);

    if (it == _btcData.end())
    {
        if (it != _btcData.begin()) --it;
        else return "";
    }
    else if (it != _btcData.begin() && it->first != date)
        --it;
    return it->first;
}

std::string BitcoinExchange::trim(const std::string &str) const
{
    size_t  first, last;

    first = str.find_first_not_of(" \t\n\r\f\v");
    if (std::string::npos == first) return "";
    last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    char*       end;
    bool        isLeap;
    long        year, month, day;
    std::string yearStr, monthStr, dayStr;
    const int   daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: date should be in the format Year-Month-Day (YYYY-MM-DD)" << std::endl;
        return false;
    }

    yearStr = date.substr(0, 4);
    monthStr = date.substr(5, 2);
    dayStr = date.substr(8, 2);

    if (yearStr.find_first_not_of("0123456789") != std::string::npos ||
        monthStr.find_first_not_of("0123456789") != std::string::npos ||
        dayStr.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << "Error: date should contain only digits" << std::endl;
        return false;
    }

    year = strtol(yearStr.c_str(), &end, 10);
    if (*end != '\0' || year < 2009 || year > 2024)
    {
        std::cout << "Error: Bitcoin data is available only between 2009 and 2024" << std::endl;
        return false;
    }

    month = strtol(monthStr.c_str(), &end, 10);
    if (*end != '\0' || month < 1 || month > 12)
    {
        std::cout << "Error: month should be between 01 and 12" << std::endl;
        return false;
    }

    day = strtol(dayStr.c_str(), &end, 10);
    if (*end != '\0')
    {
        std::cout << "Error: day should contain only digits" << std::endl;
        return false;
    }

    isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && isLeap)
    {
        if (day < 1 || day > 29)
        {
            std::cout << "Error: February in a leap year should have days between 01 and 29" << std::endl;
            return false;
        }
    }
    else
    {
        if (day < 1 || day > daysPerMonth[month - 1])
        {
            std::cout << "Error: day is out of range for the given month" << std::endl;
            return false;
        }
    }

    return true;
}
