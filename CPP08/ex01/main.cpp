#include "Span.hpp"

int main() {
    std::cout << "LARGE SPAN1" << std::endl;
    Span bigSpan(10000);
    for (int i = 0; i < 10000; ++i)
        bigSpan.addNumber(rand());

    std::cout << std::endl << "LARGE SPAN2" << std::endl;
    std::vector<int> v(10000);
    std::generate(v.begin(), v.end(), std::rand);
    bigSpan.addNumber(v.begin(), v.end());

    
    std::cout << std::endl  << "DIFFERENT TYPES OF ITERATOR" << std::endl;
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

        
}