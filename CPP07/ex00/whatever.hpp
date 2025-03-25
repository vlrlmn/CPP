/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:51:20 by vlomakin          #+#    #+#             */
/*   Updated: 2025/03/25 17:24:31 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
T min(const T& a, const T& b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

template <typename T>
T max(const T& a, const T& b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

template <typename T>
T swap(T& a, T& b) {
    T temp;

	temp = a;
	a = b;
	b = temp;
    return temp;
}

#endif