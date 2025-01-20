
#include"../include/Array.hpp"

template <typename T>
Array<T>::Array() : _element(nullptr), _len(0){}

template <typename T>
Array<T>::Array(unsigned int n) : _element(new T[n]()), _len(n){}



template <typename T>
Array<T>::Array(const Array& other) : _element(nullptr), _len(0)
{
	*this = other;
	// for(unsigned int i = 0; i < _len; i++)
	// {
	// 	_element[i] = other._element[i];
	// }
}


template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if(this != &other)
	{
		delete[] _element;
		_len = other._len;
		_element = new T[other._len]();
		for(unsigned int i = 0; i < _len; i++)
		{
			_element[i] = other._element[i];
		}
	}
	return *this;
}



template <typename T>
Array<T>::~Array()
{
	delete[] _element;
}


template <typename T>
T& Array<T>::operator[](unsigned int pos)
{
	if(pos >= _len)
		throw std::out_of_range("Index out of range");
	return _element[pos];
}

template <typename T>
const T& Array<T>::operator[](unsigned int pos) const
{
	if(pos >= _len)
		throw std::out_of_range("Index out of range");
	return _element[pos];
}

template<typename T>
int	Array<T>::size(void) const
{
	return _len;
}