/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:19:51 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/04/14 14:52:33 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &other) {
    (void)other;
}
PmergeMe &PmergeMe::operator=(PmergeMe &other) {
    if (this != &other) {
    }
    return *this;
}

void PmergeMe::printDeq() {
    for (long unsigned int i = 0; i < (unsigned long int)(std::min(int(_deq.size()), 100)); i++) {
        std::cout << _deq[i] << " ";
    }
    if (_deq.size() > 100) {
        std::cout << "....";
    }
    std::cout << std::endl;
}

void PmergeMe::printVec() {
    for (long unsigned int i = 0; i < (unsigned long int)(std::min(int(_vec.size()), 100)); i++) {
        std::cout << _vec[i] << " ";
    }
    if (_vec.size() > 100) {
        std::cout << "....";
    }
    std::cout << std::endl;
}

int PmergeMe::safeAtoi(const std::string& str) {
    std::istringstream iss(str);

    int num;
    char leftover;
    if(!(iss >> num) || (iss >> leftover)) {
        throw std::invalid_argument("Invalid input ");
    }
    return num;
}

void PmergeMe::fillContainers(int argc, char **argv) {
    std::set<int> seen;
    for (int i = 1; i < argc; i++) {
        int num = safeAtoi(argv[i]);
        if (num < 0)
            throw(std::invalid_argument("Not a number: " + std::string(argv[i])));
        _vec.push_back(num);
        _deq.push_back(num);
    }
}

int PmergeMe::Jacobsthal(int k) {
    return static_cast<int>(round((pow(2, k + 1) + pow(-1, k)) / 3));
}

void PmergeMe::sortVec() {
    if (_vec.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> pend;
    std::vector<int> sorted;

    for (size_t i = 0; i + 1 < _vec.size(); i += 2) {
        int a = _vec[i];
        int b = _vec[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }

    int last = -1;
    bool hasOdd = (_vec.size() % 2 == 1);
    if (hasOdd)
        last = _vec.back();

    std::sort(pairs.begin(), pairs.end());

    for (size_t i = 0; i < pairs.size(); ++i)
        sorted.push_back(pairs[i].first);

    for (size_t i = 0; i < pairs.size(); ++i)
        pend.push_back(pairs[i].second);

    size_t jc = 3;
    while (!pend.empty()) {
        int batch = Jacobsthal(jc) - Jacobsthal(jc - 1);
        if ((size_t)batch > pend.size()) batch = pend.size();
        for (int i = batch - 1; i >= 0; --i) {
            std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pend[i]);
            sorted.insert(pos, pend[i]);
            pend.erase(pend.begin() + i);
        }
        jc++;
    }

    if (hasOdd) {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), last);
        sorted.insert(pos, last);
    }
    _vec = sorted;
}

int PmergeMe::getDeqValue(std::deque<int> &_deq, int index)
{
    std::deque<int>::iterator it = _deq.begin();
    std::advance(it, index); 
    return *it;
}

void PmergeMe::sortDeq(std::deque<int>& _deq) {

    std::deque<int> sorted;
    std::deque<int> pending;

    for (long unsigned int i = 0; i < _deq.size(); i++)
    {
        if (i % 2 == 1)
        {
            int a = getDeqValue(_deq, i);
            int b = getDeqValue(_deq, i - 1);
            sorted.push_back(std::max(a, b));
            pending.push_back(std::min(a, b));
        }
    }
    if (_deq.size() % 2 == 1)
    {
        sorted.push_back(getDeqValue(_deq, _deq.size() - 1));
    }

    if (sorted.size() > 1)
    {
        sortDeq(sorted);
    }

    for (std::deque<int>::iterator it_p = pending.begin(); it_p != pending.end(); ++it_p)
    {
        std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), *it_p);
        sorted.insert(it, *it_p);
    }

    _deq = sorted;
}