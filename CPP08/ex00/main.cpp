/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:40:02 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/27 21:55:39 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
class MyNumber {
public:
    int value;
    MyNumber(int v) : value(v) {}
    bool operator==(const MyNumber& other) const { return value == other.value; }
    friend std::ostream& operator<<(std::ostream& os, const MyNumber& n) {
        os << n.value;
        return os;
    }
};

void testValid() {
    std::cout << "\n----- TEST VALID -----" << std::endl;
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10);

    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testInvalid() {
    std::cout << "\n----- TEST INVALID -----" << std::endl;
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10);

    try {
        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testEmpty() {
    std::cout << "\n----- TEST EMPTY CONTAINER -----" << std::endl;
    std::vector<int> empty;
    try {
        easyfind(empty, 1);
    } catch (const std::exception& e) {
        std::cerr << "Empty container: " << e.what() << std::endl;
    }
}

void testList() {
    std::cout << "\n----- TEST LIST -----" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);

    try {
        std::list<int>::iterator it = easyfind(lst, 10);
        std::cout << "List found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "List: " << e.what() << std::endl;
    }
}

void testDeque() {
    std::cout << "\n----- TEST DEQUE -----" << std::endl;
    std::deque<int> dq(3, 7);
    try {
        std::deque<int>::iterator it = easyfind(dq, 7);
        std::cout << "Deque found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Deque: " << e.what() << std::endl;
    }
}

void testRepeatedValues() {
    std::cout << "\n----- TEST REPEATED VALUES -----" << std::endl;
    std::vector<int> reps;
    reps.push_back(3);
    reps.push_back(5);
    reps.push_back(3);
    reps.push_back(7);
    reps.push_back(3);
    try {
        std::vector<int>::iterator it = easyfind(reps, 3);
        std::cout << "First occurrence (repeats): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testCustomClass() {
    std::cout << "\n----- TEST CUSTOM CLASS -----" << std::endl;
    std::vector<MyNumber> nums;
    nums.push_back(MyNumber(1));
    nums.push_back(MyNumber(2));
    nums.push_back(MyNumber(3));

    try {
        std::vector<MyNumber>::iterator it = easyfind(nums, 2);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testPointerValues() {
    std::cout << "\n----- TEST POINTER VALUES -----" << std::endl;
    int a = 10, b = 20, c = 30;
    std::vector<int*> ptrs;
    ptrs.push_back(&a);
    ptrs.push_back(&b);
    ptrs.push_back(&c);

    int* target = &b;
    std::vector<int*>::iterator it = std::find(ptrs.begin(), ptrs.end(), target);
    if (it != ptrs.end())
        std::cout << "Pointer found, value: " << **it << std::endl;
    else
        std::cout << "Pointer not found" << std::endl;
}

int main() {
    testValid();
    testInvalid();
    testEmpty();
    testList();
    testDeque();
    testRepeatedValues();
    testCustomClass();
    testPointerValues();
    return 0;
}
