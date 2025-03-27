/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:41:00 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/27 19:50:06 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
template <typename T, class Container>
MutantStack<T, Container>::MutantStack() {}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other) {
    this->c = other.c;
}

template <typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack &other) {
    if (this != &other) {
        this->c = other.c;
    }
    return *this;
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
    return this->c.begin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end() {
    return this->c.end();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin() const{
    return this->c.begin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end() const {
    return this->c.end();
}