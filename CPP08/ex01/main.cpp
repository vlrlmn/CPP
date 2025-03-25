#include "Span.hpp"

int main() {
    std::cout << "Large span way 1" << std::endl;
    Span bigSpan(10000);
    for (int i = 0; i < 10000; ++i)
        bigSpan.addNumber(rand());

    std::cout << std::endl << "Large span way2" << std::endl;
    std::vector<int> v(10000);
    std::generate(v.begin(), v.end(), std::rand);
    bigSpan.addNumber(v.begin(), v.end());
        
}