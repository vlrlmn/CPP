/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:42:59 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/26 11:45:55 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _maxNums(0), _nums() {}

Span::Span(unsigned int N): _maxNums(N), _nums() {}

Span::Span(Span &other): _maxNums(other._maxNums), _nums(other._nums) {
}

Span& Span::operator=(Span &other) {
    if (this != &other) {
        _maxNums = other._maxNums;
        _nums = other._nums;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_nums.size() > _maxNums)
        throw std::out_of_range("Limit reached. Cannot add number.");
    _nums.push_back(number);
}

int Span::shortestSpan() const {
    if (_nums.size() < 2)
        throw std::logic_error("Needed at least 2 arguments.");

    std::vector<int> tmp = _nums;

    std::sort(tmp.begin(), tmp.end());
    int minSpan = tmp[1] - tmp[0];
    for(int i = 1; i < tmp.size() - 1; i++) {
        int span = tmp[i + 1] - tmp[i];
        if (span < minSpan) 
            minSpan = span; 
    }
    return minSpan;
}

int Span::longestSpan() const {

    if (_nums.size() < 2)
        throw std::logic_error("Needed at least 2 arguments.");
    int minVal;
    int maxVal;

    maxVal = *std::min_element(_nums.begin(), _nums.end());
    maxVal = *std::max_element(_nums.begin(), _nums.end());
  
    return maxVal - maxVal;
}