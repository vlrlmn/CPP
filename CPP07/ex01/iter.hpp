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

template<typename T>
void printTemplate(T const &value) {
    std::cout << value << std::endl;
}

#endif