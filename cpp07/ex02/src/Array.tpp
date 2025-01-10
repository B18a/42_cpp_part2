


#include"../include/Array.hpp"
#include <exception>


template <typename T>
Array<T>::Array()
{
	this->element = nullptr;
};


template <typename T>
Array<T>::Array(unsigned int n)
{
	this->element = new T[n]();
};


template <typename T>
Array<T>::Array(const Array& other) : len(other.len), element(new T[other.len]())
{
	for(int i = 0; i < len; i++)
	{
		element[i] = other.element[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if(this != other)
	{
		delete[] element;
		len = other.len;
		element = new T[len]();
		for(int i = 0; i < len; i++)
		{
			element[i] = other.element[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->element;
};

template <typename T>
T& Array<T>::operator[](int pos)
{
	if(pos > this.len)
		throw std::out_of_range("Index out of range");
	return element[pos];
}


template <typename T>
int Array<T>::size(void)
{
	return len;
}



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