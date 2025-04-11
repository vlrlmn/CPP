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
        std::vector<int> _vec;
        std::deque<int> _deq;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &other);
        PmergeMe &operator=(PmergeMe &other);

        void sortVec();
        void sortDeq();
        void fillContainers(int argc, char **argv);
};

#endif