/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:08:22 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/09 13:06:57 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*Orthodox canonical form*/
BitсoinExchange::BitсoinExchange() {}

BitсoinExchange::~BitсoinExchange() {}

BitсoinExchange& BitсoinExchange::operator=(BitсoinExchange &other) { 
    return other;
}

BitсoinExchange::BitсoinExchange(BitсoinExchange &other) {
    *this = other;
}

void printMultimap(const std::multimap<std::string, double>& m) {
    for (std::multimap<std::string, double>::const_iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

/*Data processing*/
// std::string BitсoinExchange::trim(const std::string& str) {
//     size_t start = 0;
//     while (start < str.length() && std::isspace(str[start]))
//         ++start;

//     size_t end = str.length();
//     while (end > start && std::isspace(str[end - 1]))
//         --end;

//     return str.substr(start, end - start);
// }

void BitсoinExchange::parseLine(const std::string& line) { //2011-01-03 | 3
    size_t sep = line.find('|');
    if (sep == std::string::npos || sep == 0 || sep == line.size() - 1 ||
        line[sep - 1] != ' ' || line[sep + 1] != ' ') {
        throw std::invalid_argument("Error: bad input => " + line);
    }

    std::string date = line.substr(0, sep);
    std::string valueStr = line.substr(sep + 3);
    std::istringstream iss(valueStr);
    double value;
    iss >> value;
    if (iss.fail() || !iss.eof()) {
        std::string error = "Error: bad input => " + valueStr + line;
        throw std::invalid_argument(error);
    }

    if (value < 0) {
        throw (std::invalid_argument("Error: not a positive number."));
    }
    else if (value > 1000)
    {
        throw (std::invalid_argument("Error: too large a number."));
    }

    this->inputMap.insert(std::make_pair(date, value));
    std::cout << "MAP: " << std::endl;
    printMultimap(this->inputMap);
}

bool BitсoinExchange::loadInputData(const std::string& filename) {
    return loadData(filename, "date | value", 
        &BitсoinExchange::parseLine);
}

void BitсoinExchange::parseExchangeLine(const std::string& line) {

}

bool  BitсoinExchange::loadData(const std::string& filename, const std::string& header,
    Parser parser)
{
    std::ifstream in(filename);

    if (!in.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    else if (in.peek() == EOF) {
        std::cout << "File empty." << std::endl;
        in.close();
        return false;
    }
    std::string line;
    if (std::getline(in, line)) {
        if (line != header) {
            std::cerr << "Invalid header format" << std::endl;
            in.close();
            return false;
        }
    }
    while(std::getline(in, line)) {
        if (line.empty())
            continue;
        try {
            (this->*parser)(line);
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    in.close();
    return true;
}

bool BitсoinExchange::loadExchangeData(const std::string& filename)
{
    return loadData(filename, "date,exchange_rate", 
        &BitсoinExchange::parseExchangeLine);
}

void BitсoinExchange::convertData() {

}