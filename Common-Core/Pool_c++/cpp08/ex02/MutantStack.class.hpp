#ifndef MUTANTSTACK_CLASS_HPP
#define MUTANTSTACK_CLASS_HPP

#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template<typename T>

class MutantStack : public std::stack<T>
{
	public :

			MutantStack<T>(void);
			MutantStack<T>(MutantStack<T> const &src);
			~MutantStack<T>(void);

			MutantStack<T> &operator=(MutantStack<T> const &rhs);

			typedef typename std::stack<T>::container_type::iterator iterator;
			typedef typename std::stack<T>::container_type::const_iterator const_iterator;
			typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
			typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

			iterator						begin(void);
			iterator						end(void);
			const_iterator					cbegin(void) const;
			const_iterator					cend(void) const;
			reverse_iterator				rbegin(void);
			reverse_iterator				rend(void);
			const_reverse_iterator			crbegin(void) const;
			const_reverse_iterator			crend(void) const;
};

#include "MutantStack.class.tpp"

#endif