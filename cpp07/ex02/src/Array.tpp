/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:13:31 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/24 09:17:17 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Array.hpp"

/****************************************/
/*				Constructor				*/
/****************************************/

template <typename T>
Array<T>::Array() : _element(nullptr), _len(0){}

template <typename T>
Array<T>::Array(unsigned int n) : _element(new T[n]()), _len(n){}

// Copy Constructor
template <typename T>
Array<T>::Array(const Array& other) : _element(nullptr), _len(other._len)
{
	if(other._element)
	{
		_element = new T[_len];
		for(unsigned int i = 0; i < _len; i++)
			_element[i] = other._element[i];
	}
}

// Assignment Operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if(this != &other)
	{
		T* new_element = nullptr;
		if (other._len > 0) 
		{
			new_element = new T[other._len];
				for(unsigned int i = 0; i < _len; i++)
					new_element[i] = other._element[i];
		}
		delete[] _element;
		_element = new_element;
		_len = other._len;
	}
	return *this;
}

/****************************************/
/*				Destructor				*/
/****************************************/

template <typename T>
Array<T>::~Array()
{
	delete[] _element;
}

/****************************************/
/*			Operator Overload			*/
/****************************************/

template <typename T>
T& Array<T>::operator[](unsigned int pos)
{
	if(pos >= _len || pos < 0)
		throw std::out_of_range("Index out of range");
	return _element[pos];
}

template <typename T>
const T& Array<T>::operator[](unsigned int pos) const
{
	if(pos >= _len || pos < 0)
		throw std::out_of_range("Index out of range");
	return _element[pos];
}

/****************************************/
/*			Member Functions			*/
/****************************************/

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return _len;
}