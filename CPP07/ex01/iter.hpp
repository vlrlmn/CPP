/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:03:46 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/25 17:24:43 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* const arr, const int len, void(*const f)(T const &)) {
    if (!arr || !f || len < 0)
        return;
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