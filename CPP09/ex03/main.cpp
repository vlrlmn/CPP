#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Not enough arguments" << std::endl;
        return 1;
    }
    PmergeMe sort;
    sort.fillContainers(argc, argv);
    clock_t start = clock();
    clock_t end = clock();
    double timeUsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    sort.sortVec();
    sort.sortDeq();

}