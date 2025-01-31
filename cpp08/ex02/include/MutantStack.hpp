/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:56:05 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/31 15:37:10 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(MutantStack& other);
		MutantStack operator=(MutantStack& other);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator				begin();
		iterator				end();

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator			begin() const;
		const_iterator			end() const;


		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator		rbegin();
		reverse_iterator		rend();


		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	crbegin() const;
		const_reverse_iterator	crend() const;
	};

#include"../src/MutantStack.tpp"

#endif