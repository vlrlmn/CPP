/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:22:52 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/10 15:31:30 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitсoinExchange::BitсoinExchange() {}
BitсoinExchange::~BitсoinExchange() {}

BitсoinExchange::BitсoinExchange(BitсoinExchange& other) {
    *this = other;
}

BitсoinExchange& BitсoinExchange::operator=(BitсoinExchange& other) {
    if (this != &other) {
        this->inputMap = other.inputMap;
        this->exchangeMap = other.exchangeMap;
    }
    return *this;
}

std::string BitсoinExchange::trim(const std::string& str) {
    size_t start = 0;
    while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start])))
        ++start;

    size_t end = str.length();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        --end;

    return str.substr(start, end - start);
}

bool BitсoinExchange::validDate(const std::string& date) {
    struct tm tm;
    char* res = strptime(date.c_str(), "%Y-%m-%d", &tm);
    return res && *res == '\0';
}

void BitсoinExchange::parseExchangeLine(const std::string& line) {
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

void BitсoinExchange::parseInputLine(const std::string& rawLine) {
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

bool BitсoinExchange::loadData(const std::string& filename, const std::string& header, Parser parser) {
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

bool BitсoinExchange::loadExchangeData(const std::string& filename) {
    return loadData(filename, "date,exchange_rate", &BitсoinExchange::parseExchangeLine);
}

bool BitсoinExchange::loadInputData(const std::string& filename) {
    return loadData(filename, "date | value", &BitсoinExchange::parseInputLine);
}

void BitсoinExchange::convertSingle(const std::string& date, double amount) {
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