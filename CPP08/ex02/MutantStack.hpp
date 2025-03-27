#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template< class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);

		typedef typename std::stack<T, Container>::container_type container_type;
		typedef typename container_type::iterator iterator;

		typedef typename std::stack<T, Container>::container_type container_type;
		typedef typename container_type::const_iterator const_iterator;
	
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif