/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:08:16 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/10 15:24:27 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return -1;
    }

    std::string fname(argv[1]);

    BitсoinExchange btc;
    if (!btc.loadExchangeData("data.csv") )
        return 1;

    if (!btc.loadInputData(fname))
        return 1;

    btc.convertData();

    return 0;
}