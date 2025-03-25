/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:42:59 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/25 19:00:50 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _maxNums(0), _nums() {}

Span::Span(unsigned int N): _maxNums(N), _nums(){}

Span::Span(Span &other): _maxNums(other._maxNums), _nums(other._nums) {
}

Span& Span::operator=(Span &other) {
    if (this != &other) {
        _maxNums = other._maxNums;
        _nums = other._nums;
    }
    return *this;
}

Span::~Span() {
    
}

void Span::addNumber(int number) {
    try {

    } catch (std::exception &e) {
        
    }
}

int Span::shortestSpan() const {
    // std::sort() для поиска shortestSpan()
}

int Span::longestSpan() const {
    // std::min_element, std::max_element или просто *minmax_element для longestSpan()
}