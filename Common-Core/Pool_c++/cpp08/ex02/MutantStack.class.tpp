#include "MutantStack.class.hpp"

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
    std::cout << "MutantStack default constructor called" << std::endl;
    return ;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & src) : std::stack<T>(src)
{
    std::cout << "MutantStack copy constructor called" << std::endl;
    *this = src;
    return ;
}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const & rhs)
{
    std::cout << "MutantStack copy operator called" << std::endl;
    if (this != &rhs)
    {
        std::stack<T>::operator=(rhs);
    }
    return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
    std::cout << "MutantStack destructor called" << std::endl;
    return ;
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin(void)
{
    return (this->c.begin());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::cbegin(void) const
{
    return (this->c.cbegin());
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end(void)
{
    return (this->c.end());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::cend(void) const
{
    return (this->c.cend());
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin(void)
{
    return (this->c.rbegin());
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend(void)
{
    return (this->c.rend());
}

template<typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::crbegin(void) const
{
    return (this->c.crbegin());
}

template<typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::crend(void) const
{
    return (this->c.crend());
}