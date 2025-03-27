/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:45:52 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/27 21:37:02 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void subjectTest() {
    std::cout << "\n--- BASIC USAGE TEST ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Iterating over stack elements:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    std::cout << "Copied stack contents (from top to bottom):" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}

void testWithStrings() {
    std::cout << "\n--- STRING STACK TEST ---" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("Mutant");
    strStack.push("Stack");
    strStack.push("World");

    for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "\n--- COPY & ASSIGNMENT TEST ---" << std::endl;
    MutantStack<int> original;
    for (int i = 0; i < 5; ++i) original.push(i);

    MutantStack<int> copy(original);
    MutantStack<int> assigned;
    assigned = original;

    std::cout << "Copy contents:" << std::endl;
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Assigned contents:" << std::endl;
    for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void testComparisonToList() {
    std::cout << "\n--- COMPARISON TO LIST ---" << std::endl;
    std::list<int> lst;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    subjectTest();
    testWithStrings();
    testCopyAndAssignment();
    testComparisonToList();
    return 0;
}
