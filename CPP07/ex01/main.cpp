#include "Iter.hpp"

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    std::string words[] = {"hello", "world", "template"};
    std::string words2[] = {"", "world", "template"};
    std::cout << std::endl << "----TEST1-----" << std::endl;
    ::iter(numbers, 5, printTemplate);
    std::cout << std::endl  << "----TEST2-----" << std::endl;
    ::iter(words, 3, printTemplate);
    std::cout << std::endl << "----TEST3-----" << std::endl;
    ::iter(words, 0, printTemplate);
    std::cout << std::endl << "----TEST4-----" << std::endl;
    ::iter(words2, 3, printTemplate);

    std::cout << std::endl << "----TEST5-----" << std::endl;
    float fNumbers[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    ::iter(fNumbers, 5, printTemplate);
    return 0;
}