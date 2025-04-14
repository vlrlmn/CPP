/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:22:52 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/14 17:59:15 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& other) {
    if (this != &other) {
        this->inputMap = other.inputMap;
        this->exchangeMap = other.exchangeMap;
    }
    return *this;
}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t start = 0;
    while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start])))
        ++start;

    size_t end = str.length();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        --end;

    return str.substr(start, end - start);
}

bool BitcoinExchange::validDate(const std::string& dateStr) {
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    int year, month, day;
    if (sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return false;

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    struct tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon  = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 12;

    time_t temp = mktime(&tm);
    if (temp == -1)
        return false;

    return tm.tm_year == year - 1900 &&
           tm.tm_mon  == month - 1 &&
           tm.tm_mday == day;
}

void BitcoinExchange::parseExchangeLine(const std::string& line) {
    size_t sep = line.find(',');
    if (sep == std::string::npos)
        throw std::invalid_argument("Error: bad input => " + line);

    std::string date = trim(line.substr(0, sep));
    std::string valueStr = trim(line.substr(sep + 1));
    std::istringstream iss(valueStr);
    double value;
    iss >> value;

    if (iss.fail() || !iss.eof() || value < 0 || !validDate(date))
        throw std::invalid_argument("Error: bad input => " + line);

    if (exchangeMap.find(date) != exchangeMap.end())
        throw std::invalid_argument("Error: duplicate date => " + date);

    exchangeMap.insert(std::make_pair(date, value));
}

void BitcoinExchange::parseInputLine(const std::string& rawLine) {
    std::string line = trim(rawLine);
    size_t sep = line.find('|');
    if (sep == std::string::npos || sep == 0 || sep == line.size() - 1 ||
        line[sep - 1] != ' ' || line[sep + 1] != ' ') {
        throw std::invalid_argument("Error: bad input => " + rawLine);
    }

    std::string date = trim(line.substr(0, sep));
    std::string valueStr = trim(line.substr(sep + 1));
    std::istringstream iss(valueStr);
    double value;
    iss >> value;

    if (iss.fail() || !iss.eof())
        throw std::invalid_argument("Error: bad input => " + rawLine);
    if (value < 0)
        throw std::invalid_argument("Error: not a positive number.");
    if (value > 1000)
        throw std::invalid_argument("Error: too large a number.");
    if (!validDate(date))
        throw std::invalid_argument("Error: bad input => " + rawLine);

    convertSingle(date, value);
}

bool BitcoinExchange::loadData(const std::string& filename, const std::string& header, Parser parser) {
    std::ifstream in(filename.c_str());
    if (!in.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return false;
    }

    std::string line;
    if (std::getline(in, line)) {
        if (trim(line) != header) {
            std::cerr << "Error: invalid header format in " << filename << std::endl;
            return false;
        }
    }

    while (std::getline(in, line)) {
        if (line.empty())
            continue;
        try {
            (this->*parser)(line);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    in.close();
    return true;
}

bool BitcoinExchange::loadExchangeData(const std::string& filename) {
    return loadData(filename, "date,exchange_rate", &BitcoinExchange::parseExchangeLine);
}

bool BitcoinExchange::loadInputData(const std::string& filename) {
    return loadData(filename, "date | value", &BitcoinExchange::parseInputLine);
}

void BitcoinExchange::convertSingle(const std::string& date, double amount) {
    if (date > exchangeMap.rbegin()->first) {
        std::cerr << "Error: no exchange rate after " << exchangeMap.rbegin()->first 
                << " (requested: " << date << ")" << std::endl;
        return;
    }
    std::map<std::string, double>::const_iterator it = exchangeMap.lower_bound(date);
    if (it == exchangeMap.end() || it->first != date) {
        if (it == exchangeMap.begin()) {
            std::cerr << "Error: no exchange rate before " << date << std::endl;
            return;
        }
        --it;
    }
    double rate = it->second;
    double result = amount * rate;
    std::cout << date << " => " << amount << " = " << result << std::endl;
}