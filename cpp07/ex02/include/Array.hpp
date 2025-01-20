
#include<iostream>

#pragma once

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T*				_element;
		unsigned int	_len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](unsigned int pos);
		const T& operator[](unsigned int pos) const;
		int	size(void);

};

#endif



// Allocating Memory using () initializes the value to 0
/*
    int*	i = new int();			// Default-initialized to 0
    float*	f = new float();		// Default-initialized to 0.0
    double*	d = new double();		// Default-initialized to 0.0
    char*	c = new char();			// Default-initialized to '\0'

    int*	i_uninit = new int;		// Uninitialized (garbage value)
    float*	f_uninit = new float;	// Uninitialized (garbage value)
    double*	d_uninit = new double;	// Uninitialized (garbage value)
    char*	c_uninit = new char;	// Uninitialized (garbage value)


// std::string is a class type with constructors that handle initialization:

    std::string* s1 = new std::string();  // Default-initialized to ""
    std::string* s2 = new std::string;   // Also default-initialized to ""

*/

/*********************************/
/*	Example of Template Class 	*/
/*********************************/

// template <typename T>
// class Math
// {
// 	private:
// 		T first;
// 		T second;

// 	public:
// 		Math(){	};			// Default Constructor
// 		Math(T a, T b)		// Constructor with Parameters
// 		{
// 			first = a;
// 			second = b;
// 		};
// 		void addnumbers();
// };


/********************************************************/
/*	whenever a function is defined outside of a class 	*/
/*	the template statement has to be written again 		*/
/********************************************************/
// template <typename T>
// void Math<T>::addnumbers()
// {
// 	std::cout<< this->first << " " << this->second << std::endl;
// }

// template <typename T>
// inline Array<T>::Array()
// {
// }
