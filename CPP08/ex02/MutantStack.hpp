#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template< class T, class Container = std::deque<T> >
class MutantStack : {
	private:
		std::stack<int> _nums;
		size_t _stackSize;
		int top;
		T* stackPtr;
	public:
		MutantStack();
		~MutantStack();
		MutantStack(MutantStack &other);
		MutantStack &operator=(MutantStack &other);

		void push(const &T);
		void pop(T&);
		size_t size();
		void top();

};

template<typename T>
typename T::iterator easyfind() {
	
}

#include "MutantStack.tpp"

#endif