/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:03:36 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/25 17:24:50 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>

template<typename T>
class Array {
    private:
        T* _arr;
        unsigned int _size;
    
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;

};

#include "Array.tpp"

#endif