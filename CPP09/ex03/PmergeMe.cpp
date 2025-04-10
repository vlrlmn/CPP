#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &other) {}
PmergeMe &PmergeMe::operator=(PmergeMe &other) {}

void PmergeMe::fillContainers(int argc, char **argv) {
    int num;
    for (int i = 0; i < argc; i++) {
        num = std::stoi(argv[i]);
        if (num < 0)
            throw(std::invalid_argument("Not a number!"));
    }
    _vec.push_back(num);
    _deq.push_back(num);
}