#include "Array.hpp"

#define MAX_VAL 5

void testIntArray() {
    try {
        std::cout << std::endl << "----TEST INTEGERS----" << std::endl ;
        Array<int> numbers(MAX_VAL);
        std::cout <<  "~~~~Test initialization~~~~" << std::endl;
        for (unsigned int i = 0; i < 5; ++i) {
            std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
        }
        std::cout  << std::endl <<  "~~~~Test assignment~~~~" << std::endl;
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            numbers[i] = i * 2;
        }
        for (unsigned int i = 0; i < 7; ++i) {
            std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void testStringArray() {
    std::cout << std::endl << "----TEST STRINGS----" << std::endl ;
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "Array";
    words[2] = "World";

    for (unsigned int i = 0; i < words.size(); ++i) {
        std::cout << "words[" << i << "] = " << words[i] << std::endl;
    }
    try {
        std::cout << "words[" << 4 << "] = " << words[4] << std::endl;
    }  catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void testCopyAndAssign() {
    std::cout << std::endl << "-----TEST DEEP COPYING----" << std::endl ;
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
    std::cout << std::endl << "-----NEGATIVE TEST CASES-----" << std::endl;
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

void testCopyAndAssignPointerRef() {
    std::cout << std::endl << "----TEST COPY CONSTRUCTOR BY REF----" << std::endl;

    Array<int> original(3);
    for (unsigned int i = 0; i < original.size(); ++i)
        original[i] = i + 1;
    std::cout <<  "~~~~Copy assignment by ref~~~~" << std::endl;
    const Array<int>& ref = original;
    Array<int> copyFromRef(ref);
    copyFromRef[0] = 999;

    std::cout << "original[0] = " << original[0] << " (should be 1)" << std::endl;
    std::cout << "copyFromRef[0] = " << copyFromRef[0] << " (should be 999)" << std::endl;


    Array<int> assignRef(1); 
    assignRef = ref;
    std::cout << "assignRef[1] = " << assignRef[1] << " (should be 2)" << std::endl;

    std::cout << std::endl <<  "~~~~Copy assignment by pointer~~~~" << std::endl;
    const Array<int>* ptr = &original;
    Array<int> assignFromPtr(3);
    assignFromPtr = *ptr;
    std::cout << "assignFromPtr[2] = " << assignFromPtr[2] << " (should be 3)" << std::endl;
    assignFromPtr[1] = 888;
    std::cout << "original[1] = " << original[1] << " (should be 2)" << std::endl;
    std::cout << "assignFromPtr[1] = " << assignFromPtr[1] << " (should be 888)" << std::endl << std::endl;
}

int main() {
    testIntArray();
    testStringArray();
    testCopyAndAssign();
    testOutOfBounds();
    testCopyAndAssignPointerRef();

    return 0;
}
