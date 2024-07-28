/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:37:28 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/27 17:35:38 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <deque>

class BitcoinExchange {
public:

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange& operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string &filename);
    bool loadInput(const std::string &filename);
    void evaluate() const;

private:
    std::map<std::string, double> _btcData;
    std::deque<std::pair<std::string, std::string> > _inputData;

    std::string findClosestDate(const std::string &date) const;
    std::string trim(const std::string &str) const;
    bool isValidDate(const std::string &date) const;
};

#endif
