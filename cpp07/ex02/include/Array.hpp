
#include<iostream>

#pragma once

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T*				element;
		unsigned int	len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](int pos);
		int	size(void);

};

#endif



template <typename T>
class Math
{
	private:
		T first;
		T second;

	public:
		Math(){	};			// Default Constructor
		Math(T a, T b)		// Constructor with Parameters
		{
			first = a;
			second = b;
		};
		void addnumbers();
};






/********************************************************/
/*	whenever a function is defined outside of a class 	*/
/*	the template statement has to be written again 		*/
/********************************************************/
template <typename T>
void Math<T>::addnumbers()
{
	std::cout<< this->first << " " << this->second << std::endl;
}
