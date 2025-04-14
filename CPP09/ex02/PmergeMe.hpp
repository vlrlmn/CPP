/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:08:17 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/14 13:29:24 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>
#include <cmath>
#include <sys/time.h>
#include <iomanip>
#include <sstream>
#include <set>

class PmergeMe {
    private:
        int Jacobsthal(int k);
        
        public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &other);
        PmergeMe &operator=(PmergeMe &other);

        std::vector<int> _vec;
        std::deque<int> _deq;
        void fillContainers(int argc, char **argv);
        void sortVec();
        void sortDeq(std::deque<int>& _deq);
        void printVec();
        void printDeq();
        int safeAtoi(const std::string& str);
        int getDeqValue(std::deque<int> &deq, int index);
    
};

#endif