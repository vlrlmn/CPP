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
            if (!seen.insert(num).second) {
                std::cerr << "Notice: duplicate value '" << argv[i] << "' ignored." << std::endl;
                continue;
            }
        _vec.push_back(num);
        _deq.push_back(num);
    }
}

int PmergeMe::Jacobsthal(int k) {
    return static_cast<int>(round((pow(2, k + 1) + pow(-1, k)) / 3));
}


void PmergeMe::insert(std::vector<int>& main, std::vector<int>& pend, int odd, std::vector<int>& left, std::vector<int>& vec, bool is_odd, int order) {
    std::vector<int>::iterator end;
    if (pend.size() == 1) {
        end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());
    } else if (pend.size() > 1) {
        size_t jc = 3, count = 0, idx, decrease;
        while (!pend.empty()) {
            idx = Jacobsthal(jc) - Jacobsthal(jc - 1);
            if (idx > pend.size()) idx = pend.size();
            decrease = 0;
            while (idx) {
                end = main.begin();
                if (Jacobsthal(jc + count) - decrease <= main.size())
                    end = main.begin() + Jacobsthal(jc + count) - decrease;
                else
                    end = main.end();
                end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
                main.insert(end, *(pend.begin() + idx - 1));
                pend.erase(pend.begin() + idx - 1);
                idx--;
                decrease++;
                count++;
            }
            jc++;
        }
    }

    std::vector<int> result;
    if (is_odd) {
        end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }
    for (std::vector<int>::iterator i = main.begin(); i != main.end(); ++i) {
        std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), *i);
        result.insert(result.end(), it - (order - 1), it + 1);
    }
    result.insert(result.end(), left.begin(), left.end());
    vec = result;
}

void PmergeMe::sortVec() {
    static int order = 1;
    int unit_size = _vec.size() / order;
    if (unit_size < 2) return;

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

    for (std::vector<int>::iterator it = start + order * 2; it < end; it += order) {
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
    std::vector<int> tempVec(_deq.begin(), _deq.end());
    static int order = 1;
    int unit_size = tempVec.size() / order;
    if (unit_size < 2) return;

    bool is_odd = unit_size % 2 == 1;
    std::vector<int>::iterator start = tempVec.begin();
    std::vector<int>::iterator end = tempVec.begin() + ((order * unit_size) - (is_odd * order));

    for (std::vector<int>::iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + (order * 2 - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }

    order *= 2;
    sortDeq();
    order /= 2;

    std::vector<int> main, pend, left;
    int odd = 0;

    main.push_back(*(start + order - 1));
    main.push_back(*(start + order * 2 - 1));

    for (std::vector<int>::iterator it = start + order * 2; it < end; it += order) {
        pend.push_back(*(it + order - 1));
        it += order;
        if (it < end)
            main.push_back(*(it + order - 1));
    }

    if (is_odd)
        odd = *(end + order - 1);
    left.insert(left.end(), end + (order * is_odd), tempVec.end());

    for (std::vector<int>::iterator it = pend.begin(); it != pend.end(); ++it) {
        std::vector<int>::iterator pos = std::upper_bound(main.begin(), main.end(), *it);
        main.insert(pos, *it);
    }
    if (is_odd) {
        std::vector<int>::iterator pos = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(pos, odd);
    }

    tempVec.clear();
    tempVec.insert(tempVec.end(), main.begin(), main.end());
    tempVec.insert(tempVec.end(), left.begin(), left.end());

    _deq.assign(tempVec.begin(), tempVec.end());
}
