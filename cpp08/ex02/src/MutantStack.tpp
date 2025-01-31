/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:57 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/31 15:37:53 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../include/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T>& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T> MutantStack<T>::operator=(MutantStack<T>& other)
{
    if (this != &other) 
	{
        std::stack<T>::operator=(other);
    }
    return *this;
}

/****************************************/
/*				Iterator	 			*/
/****************************************/

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

/****************************************/
/*			Const Iterator	 			*/
/****************************************/

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

/****************************************/
/*			Reverse Iterator 			*/
/****************************************/

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

/****************************************/
/*			Const Reverse Iterator		*/
/****************************************/

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
	return this->c.crbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
	return this->c.crend();
}
