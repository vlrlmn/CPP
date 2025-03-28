/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:40:02 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/28 11:58:31 by vlomakin         ###   ########.fr       */
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

void testCustomClass() {
    std::cout  << std::endl <<  "----- TEST CUSTOM CLASS -----" << std::endl;
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

void testValid() {
    std::cout << std::endl << "----- TEST VALID -----" << std::endl;
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
    std::cout << std::endl << "----- TEST INVALID -----" << std::endl;
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
    std::cout << std::endl << "----- TEST EMPTY CONTAINER -----" << std::endl;
    std::vector<int> empty;
    try {
        easyfind(empty, 1);
    } catch (const std::exception& e) {
        std::cerr << "Empty container: " << e.what() << std::endl;
    }
}

void testList() {
    std::cout  << std::endl <<  "----- TEST LIST -----" << std::endl;
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
    std::cout  << std::endl <<  "----- TEST DEQUE -----" << std::endl;
    std::deque<int> dq(3, 7);
    try {
        std::deque<int>::iterator it = easyfind(dq, 7);
        std::cout << "Deque found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Deque: " << e.what() << std::endl;
    }
}

void testRepeatedValues() {
    std::cout  << std::endl <<  "----- TEST REPEATED VALUES -----" << std::endl;
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

int main() {
    testValid();
    testInvalid();
    testEmpty();
    testList();
    testDeque();
    testRepeatedValues();
    testCustomClass();
    return 0;
}
