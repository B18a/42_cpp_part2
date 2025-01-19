


#include"../include/Array.hpp"
#include <exception>


// template <class T>
// Array<T>::Array()
// {
// 	this->_element = nullptr;
// };


// template <typename T>
// Array<T>::Array(unsigned int n)
// {
// 	this->_element = new T[n]();
// };


// template <typename T>
// Array<T>::Array(const Array& other) : _len(other._len), _element(new T[other._len]())
// {
// 	for(int i = 0; i < _len; i++)
// 	{
// 		_element[i] = other._element[i];
// 	}
// }

// template <typename T>
// Array<T>& Array<T>::operator=(const Array& other)
// {
// 	if(this != other)
// 	{
// 		delete[] _element;
// 		_len = other._len;
// 		_element = new T[other._len]();
// 		for(int i = 0; i < _len; i++)
// 		{
// 			_element[i] = other._element[i];
// 		}
// 	}
// 	return *this;
// }

// template <typename T>
// Array<T>::~Array()
// {
// 	delete[] this->_element;
// };

// template <typename T>
// T& Array<T>::operator[](int pos)
// {
// 	if(pos > this._len)
// 		throw std::out_of_range("Index out of range");
// 	return _element[pos];
// }


// template <typename T>
// int Array<T>::size(void)
// {
// 	return _len;
// }


