/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:24:58 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/26 12:59:11 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>


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
                throw std::length_error("Numbers cannot be added. Not enough space.");
            _nums.insert(_nums.end(), begin, end);
        }

        int shortestSpan() const;
        int longestSpan() const;
        void printContent() const;
};

#endif