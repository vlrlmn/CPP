/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:41:00 by lomakinaval       #+#    #+#             */
/*   Updated: 2025/03/28 12:11:29 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
template <typename T, class Container>
MutantStack<T, Container>::MutantStack() {}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other):  std::stack<T, Container>(other) {
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