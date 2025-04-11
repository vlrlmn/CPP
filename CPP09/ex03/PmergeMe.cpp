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

void PmergeMe::sortVec() {
    static int order = 1;
    int unit_size = _vec.size() / order;
    if (unit_size < 2)
        return ;
    bool is_odd = unit_size % 2 == 1;
    std::vector<int>::iterator start = _vec.begin();
    std::vector<int>::iterator end = _vec.begin() + ((order * unit_size) - (is_odd * order));
    
    for (std::vector<int>::iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + (order * 2 - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }
    order *= 2;
    sortVec();
    order /= 2;
}

void PmergeMe::sortDeq() {

}