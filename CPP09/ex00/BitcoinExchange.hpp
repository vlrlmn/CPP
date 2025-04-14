/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:08:38 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/10 15:43:14 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <sstream>

class BitcoinExchange {
    private:
        typedef void (BitcoinExchange::*Parser)(const std::string&);

        std::multimap<std::string, double> inputMap;
        std::map<std::string, double> exchangeMap;
        std::string name;

        bool loadData(const std::string& filename, const std::string& header, Parser parser);
        void convertSingle(const std::string& date, double amount);
        void parseExchangeLine(const std::string& line);
        void parseInputLine(const std::string& line);
        bool validDate(const std::string& date);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange& operator=(BitcoinExchange &other);
        BitcoinExchange(BitcoinExchange &other);

        bool loadExchangeData(const std::string& filename);
        bool loadInputData(const std::string& filename);
        std::string trim(const std::string& str);
};
#endif