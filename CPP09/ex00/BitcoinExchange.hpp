# pragma once

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <cctype> 

class BitсoinExchange {
    private:
        std::multimap<std::string, double> inputMap;
        std::map<std::string, double> exchangeMap;
        std::string name;
    public:
        BitсoinExchange();
        ~BitсoinExchange();
        BitсoinExchange& operator=(BitсoinExchange &other);
        BitсoinExchange(BitсoinExchange &other);

        bool loadExchangeData(char *filename);
        bool loadInputData(char *filename);
        void convertData();
        std::string trim(const std::string& str);

};
#endif