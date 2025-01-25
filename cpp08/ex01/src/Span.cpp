
#include"../include/Span.hpp"
#include<iostream>

template <typename T>Span<T>::Span(void){}

template <typename T>Span<T>::Span(unsigned int size)
{
	container(size, 3); 
}
template <typename T> Span<T>::~Span(void){}

template <typename T> Span<T>::Span(const Span &other){*this = other;}

template <typename T> Span<T> Span<T>::operator=(const Span &other)
{
	if(this != &other)
	{

	}
	return *this; 
}


template <typename T> void Span<T>::addNumber()
{

}


template <typename T> void Span<T>::shortestSpan()
{

}

template <typename T> void Span<T>::longestSpan()
{

}