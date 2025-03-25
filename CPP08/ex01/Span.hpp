/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:24:58 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/25 18:49:05 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Span {
    private:
        unsigned int _maxNums;
        std::vector<int> _nums;

    public:
        Span();
        Span(unsigned int N);
        Span(Span &other);
        Span& operator=(Span &other);
        ~Span();

        void addNumber(int number);

        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end) {
            if (_nums.size() + std::distance(begin, end) > _maxNums)
                throw std::out_of_range("Not enough space");
            _nums.insert(_nums.end(), begin, end);
        }

        int shortestSpan() const;
        int longestSpan() const;

};

#endif