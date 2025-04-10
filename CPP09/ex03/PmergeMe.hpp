# pragma once

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe {
    private:

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &other);
        PmergeMe &operator=(PmergeMe &other);

        void sortWithVector(std::vector<int>& vec);
        void sortWithDeque(std::deque<int>& deq);

};

#endif