/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:08:16 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/08 22:02:25 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

    std::multimap<std::string, std::string> convertInput;
    std::map<std::string, std::string> convertTable; // check that dates are unique in parsing, can use lower_bound for lower date

    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return -1;
    }
    
    char *infile = argv[1];
    std::string fname(argv[1]);

    BitсoinExchange btc;
    if (!btc.loadExchangeData("data.csv") )
        return 1;

    if (!btc.loadInputData(fname))
        return 1;

    btc.convertData();

    return 0;
}