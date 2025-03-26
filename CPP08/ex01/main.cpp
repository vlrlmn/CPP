#include "Span.hpp"

int main() {
    std::cout << "----- ADD NUMBERS TESTS -----" << std::endl;
    std::cout << "~~~Large span1~~~" << std::endl;
    Span bigSpan(10000);
    for (int i = 0; i < 10000; ++i) {
        bigSpan.addNumber(rand());
    }
    std::cout << std::endl << "~~~Large span2~~~" << std::endl;
    std::vector<int> v(10000);
    std::generate(v.begin(), v.end(), std::rand);
    bigSpan.addNumber(v.begin(), v.end());

    
    std::cout << std::endl  << "~~~Different types of iterator~~~" << std::endl;
    Span sp(20);
    std::vector<int> vec;
    std::list<int> lst;
    std::deque<int> dq;
    int arr[] = {1, 2, 3};
    try {
        sp.addNumber(vec.begin(), vec.end());
        sp.addNumber(lst.begin(), lst.end());
        sp.addNumber(dq.begin(), dq.end());
        sp.addNumber(arr, arr + 3);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- SPAN TESTS -----" << std::endl;
    std::cout << "~~~Not enough numbers~~~" << std::endl;
    Span tooSmall(1);
    tooSmall.addNumber(42);

    try {
        tooSmall.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << "shortestSpan(): " << e.what() << std::endl;
    }

    try {
        tooSmall.longestSpan();
    } catch (const std::exception &e) {
        std::cout << "longestSpan(): " << e.what() << std::endl;
    }
    std::cout << std::endl << "~~~Two numbers~~~" << std::endl;
    Span twoNums(1);
    twoNums.addNumber(42);
    twoNums.addNumber(41);
    std::cout << twoNums.shortestSpan() << std::endl;
    std::cout << twoNums.longestSpan() << std::endl;

    std::cout << std::endl << "~~~Two equal numbers~~~" << std::endl;
    Span eqNums(1);
    eqNums.addNumber(42);
    eqNums.addNumber(42);
    std::cout << eqNums.shortestSpan() << std::endl;
    std::cout << eqNums.longestSpan() << std::endl;
}