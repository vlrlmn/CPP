#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* const arr, const int len, void(*const f)(T const &)) {
    for (int i = 0; i < len; i++)
    {
        f(arr[i]);
    }
}

void printInt(int const &x) {
    std::cout << x << std::endl;
}

void printString(std::string const &str) {
    std::cout << str << std::endl;
}

#endif