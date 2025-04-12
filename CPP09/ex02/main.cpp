/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:08:07 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/12 13:20:11 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Not enough arguments" << std::endl;
        return 1;
    }
    PmergeMe sort;
    try {
        sort.fillContainers(argc, argv);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    clock_t startVec, endVec;
    clock_t startDeq, endDeq;

    std::cout << "Before: ";
    sort.printVec();

    startVec = clock();
    sort.sortVec();
    endVec = clock();

    startDeq = clock();
    sort.sortDeq();
    endDeq = clock();

    std::cout << "After: ";
    sort.printVec();
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << sort._vec.size() << " elements with std::vector : " 
                << double(endVec - startVec) / CLOCKS_PER_SEC << std::endl;
    
    std::cout << "Time to process a range of " << sort._vec.size() << " elements with std::deque : "
                << double(endDeq - startDeq) / CLOCKS_PER_SEC << std::endl;
    
    return 0;
}