/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:48:32 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/25 17:21:13 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10);

    std::cout << "-----TEST VALID----" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << "-----TEST INVALID----" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "-----TEST EMPTY CONTAINER----" << std::endl;
    std::vector<int> empty;
    try {
        easyfind(empty, 1);
    } catch (const std::exception& e) {
        std::cerr << "Empty container: " << e.what() << std::endl;
    }
    std::cout << std::endl << "-----TEST LIST----" << std::endl;
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

    std::cout << std::endl << "-----TEST DEQUE----" << std::endl;
    std::deque<int> dq(3, 7);
    try {
        std::deque<int>::iterator it = easyfind(dq, 7);
        std::cout << "Deque found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Deque: " << e.what() << std::endl;
    }

    std::cout << std::endl << "-----VALUES OF REPEAT----" << std::endl;
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

    return 0;
}
