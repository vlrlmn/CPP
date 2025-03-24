#include "Array.hpp"

#define MAX_VAL 750

void testIntArray() {
    std::cout << std::endl << "----testIntArray()----" << std::endl ;
    Array<int> numbers(MAX_VAL);
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        numbers[i] = i * 2;
    }
    for (unsigned int i = 0; i < 5; ++i) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
}

void testStringArray() {
    std::cout << std::endl << "----testStringArray()----" << std::endl ;
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "Array";
    words[2] = "World";

    for (unsigned int i = 0; i < words.size(); ++i) {
        std::cout << "words[" << i << "] = " << words[i] << std::endl;
    }
}

void testCopyAndAssign() {
    std::cout << std::endl << "-----testCopyAndAssign()----" << std::endl ;
    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); ++i)
        original[i] = i;

    Array<int> copy = original;
    copy[0] = 999;

    std::cout << "original[0] = " << original[0] << " (should be 0)" << std::endl;
    std::cout << "copy[0] = " << copy[0] << " (should be 999)" << std::endl;

    Array<int> assigned(1);
    assigned = original;
    std::cout << "assigned[1] = " << assigned[1] << " (should be 1)" << std::endl;
}

void testOutOfBounds() {
    std::cout << std::endl << "-----testOutOfBounds()-----" << std::endl;
    Array<int> a(10);

    try {
        a[-1] = 5;
    } catch (const std::exception& e) {
        std::cerr << "Exception (negative): " << e.what() << std::endl;
    }

    try {
        a[10] = 5;
    } catch (const std::exception& e) {
        std::cerr << "Exception (too large): " << e.what() << std::endl;
    }
}

int main() {
    testIntArray();
    testStringArray();
    testCopyAndAssign();
    testOutOfBounds();

    return 0;
}
