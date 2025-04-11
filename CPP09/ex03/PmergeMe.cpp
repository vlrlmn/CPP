#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &other) {}
PmergeMe &PmergeMe::operator=(PmergeMe &other) {}

void PmergeMe::printDeq() {

}

void PmergeMe::printVec() {

}

int PmergeMe::safeAtoi(const std::string& str) {
    std::istringstream iss(str);

    int num;
    char leftover;
    if(!(iss >> num) || (iss >> leftover)) {
        throw std::invalid_argument("Invalid input: " + str);
    }
    return num;
}

void PmergeMe::fillContainers(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        int num = safeAtoi(argv[i]);
        if (num < 0)
            throw(std::invalid_argument("Not a number: " + std::string(argv[i])));
        _vec.push_back(num);
        _deq.push_back(num);
    }
}

int PmergeMe::Jacobsthal(int k) {

}

void PmergeMe::insert(std::vector<int>& main, std::vector<int>& pend, int odd, std::vector<int>& left, std::vector<int>& vec, bool is_odd, int order) {

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

    std::vector<int> main, pend, left;
    int odd = 0;

    main.push_back(*(start + order - 1));
    main.push_back(*(start + order * 2 - 1));

    for(std::vector<int>::iterator it = start + order * 2; it < end; it += order) {
        pend.push_back(*(it + order - 1));
        it += order;
        if (it < end)
            main.push_back(*(it + order - 1));
    }

    if (is_odd)
        odd = *(end + order - 1);
    left.insert(left.end(), end + (order * is_odd), _vec.end());

    if (is_odd || !pend.empty())
        insert(main, pend, odd, left, _vec, is_odd, order);
}

void PmergeMe::sortDeq() {

}