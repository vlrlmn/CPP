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

/*Data processing*/
std::string BitсoinExchange::trim(const std::string& str) {
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start]))
        ++start;

    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1]))
        --end;

    return str.substr(start, end - start);
}

bool BitсoinExchange::loadExchangeData(char *filename) {

}

bool BitсoinExchange::loadInputData(char *filename) {
    std::ifstream in(filename);
    if (!in.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    else if (in.peek() == EOF)
    {
        std::cout << "File empty." << std::endl;
        in.close();
        return false;
    }

    std::string line;
    if (std::getline(in, line)) {
        if (trim(line) != "date | value") {
            std::cerr << "Invalid header format" << std::endl;
            in.close();
            return false;
        }
    }
    std::cout << "kek" << std::endl;
    while(std::getline(in, line)) {
        if (line.empty())
            continue;
        
    }

    in.close();
    return true;
}

void BitсoinExchange::convertData() {

}