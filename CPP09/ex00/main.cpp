#include "BitcoinExchange.hpp"

std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start]))
        ++start;

    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1]))
        --end;

    return str.substr(start, end - start);
}

bool validHeaderFormat(std::string line) {
    return line == "date | value";
}

bool validFileContent(char *infile) {

    std::ifstream in(infile);
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
        if (!validHeaderFormat(line)) {
            std::cerr << "Invalid header format" << std::endl;
            in.close();
            return false;
        }
    }
    std::cout << "kek" << std::endl;
    while(std::getline(in, line)) {

    }

    in.close();
    return true;
}

int main(int argc, char **argv) {

    std::multimap<std::string, std::string> convertInput;
    std::map<std::string, std::string> convertTable; // check that dates are unique, can use lower_bound for lower date

    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return -1;
    }

    char *infile = argv[1];
    if (!validFileContent(infile)) {
        return -1;
    }
    else
        return 0;
}