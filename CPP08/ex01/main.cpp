/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:36:31 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/27 21:58:53 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstdlib>

void testLargeSpan() {
    std::cout << "----- ADD NUMBERS TESTS -----" << std::endl;
    std::cout << "~~~Large span1~~~" << std::endl;
    Span bigSpan(10000);
    for (int i = 0; i < 10000; ++i)
        bigSpan.addNumber(rand());
    std::cout << "SUCCESS! Added values." << std::endl;

    std::cout << std::endl << "~~~Large span2~~~" << std::endl;
    std::vector<int> v(10000);
    try {
        std::generate(v.begin(), v.end(), std::rand);
        bigSpan.addNumber(v.begin(), v.end());
    } catch (std::exception &e) {
        std::cout << "Add to large span: " << e.what() << std::endl;
    }
}

void testFixedSpan() {
    std::cout << std::endl << "~~~Fixed values~~~" << std::endl;
    Span fixed(5);
    fixed.addNumber(-3);
    fixed.addNumber(-3);
    fixed.addNumber(17);
    fixed.addNumber(9);
    fixed.addNumber(11);
    fixed.printContent();
    std::cout << "SUCCESS! Shortest span: " << fixed.shortestSpan() << std::endl;
    std::cout << "SUCCESS! Longest span: " << fixed.longestSpan() << std::endl;
}

void testVariousIterators() {
    std::cout << std::endl << "~~~Different types of iterator~~~" << std::endl;
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
        sp.printContent();
        std::cout << "SUCCESS! Numbers added." << std::endl;
    } catch (std::exception &e) {
        std::cout << "FAIL! " << e.what() << std::endl;
    }
}

void testOutOfBounds() {
    std::cout << std::endl << "~~~Out of limits values~~~" << std::endl;
    Span outVals(3);
    try {
        outVals.addNumber(-3);
        outVals.addNumber(-3);
        outVals.addNumber(17);
        outVals.addNumber(9);
        outVals.addNumber(11);

        std::cout << "SUCCESS! Shortest span: " << outVals.shortestSpan() << std::endl;
        std::cout << "SUCCESS! Longest span: " << outVals.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "FAIL! " << e.what() << std::endl;
    }
}

void testTooSmall() {
    std::cout << std::endl << "~~~Not enough numbers~~~" << std::endl;
    Span tooSmall(1);
    tooSmall.addNumber(42);

    try {
        tooSmall.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << "FAIL! shortestSpan(): " << e.what() << std::endl;
    }

    try {
        tooSmall.longestSpan();
    } catch (const std::exception &e) {
        std::cout << "FAIL! longestSpan(): " << e.what() << std::endl;
    }
}

void testTwoNumbers() {
    std::cout << std::endl << "~~~Two numbers~~~" << std::endl;
    Span twoNums(1);
    twoNums.addNumber(42);
    twoNums.addNumber(41);
    twoNums.printContent();
    std::cout << "SUCCESS! Shortest span: " << twoNums.shortestSpan() << std::endl;
    std::cout << "SUCCESS! Longest span: " << twoNums.longestSpan() << std::endl;
}

void testEqualNumbers() {
    std::cout << std::endl << "~~~Two equal numbers~~~" << std::endl;
    Span eqNums(1);
    eqNums.addNumber(42);
    eqNums.addNumber(42);
    eqNums.printContent();
    std::cout << "SUCCESS! Shortest span: "  << eqNums.shortestSpan() << std::endl;
    std::cout << "SUCCESS! Longest span: " << eqNums.longestSpan() << std::endl;
}
class MyNumber {
public:
    int value;
    MyNumber(int v) : value(v) {}
    bool operator==(const MyNumber& other) const { return value == other.value; }
    bool operator<(const MyNumber& other) const { return value < other.value; }
    operator int() const { return value; }
};

void testWithCustomClass() {
    std::cout << std::endl << "~~~Custom class test~~~" << std::endl;
    Span customSpan(3);
    MyNumber a(10), b(20), c(15);
    customSpan.addNumber(a);
    customSpan.addNumber(b);
    customSpan.addNumber(c);
    std::cout << "Shortest span: " << customSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << customSpan.longestSpan() << std::endl;
}

int main() {
    testLargeSpan();
    testFixedSpan();
    testVariousIterators();
    testOutOfBounds();
    testTooSmall();
    testTwoNumbers();
    testEqualNumbers();
    testWithCustomClass();
    return 0;
}
