
#include"../include/Span.hpp"
#include<iostream>
#include<algorithm>

Span::Span(void){}
Span::Span(unsigned int size) : N(size) {}
Span::~Span(void){}
Span::Span(const Span &other){*this = other;}

Span Span::operator=(const Span &other)
{
	if(this != &other)
	{
		this->N = other.N;
		this->container = other.container;
	}
	return *this; 
}


void Span::addNumber(int number)
{
	if(container.size() >= N)
		throw std::overflow_error("Overflow!");
	else
		container.push_back(number);
}


int Span::shortestSpan(void) const
{
	int minDistance = std::numeric_limits<int>::max();;

	if(container.size() < 2)
		throw std::range_error("Size to small!");
    std::vector<int> sortedContainer = container;
	std::sort(sortedContainer.begin(), sortedContainer.end());
	for(unsigned int i = 1; i < sortedContainer.size(); i++)
	{
		int distance = sortedContainer[i] - sortedContainer[i - 1];
		minDistance = std::min(minDistance, distance);
	}
	return (minDistance);
}

int Span::longestSpan(void) const
{
	if(container.size() < 2)
		throw std::range_error("Size to small!");
	auto min_it = std::min_element(container.begin(), container.end());
	auto max_it = std::max_element(container.begin(), container.end());

	return (*max_it - *min_it);
}


// std::vector<int>::const_iterator max = std::max_element(container.begin(), container.end());
// std::vector<int>::const_iterator min = std::min_element(container.begin(), container.end());


void Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (container.size() + std::distance(begin, end) > N)
		throw std::overflow_error("Overflow!");
	container.insert(container.end(), begin, end);
}