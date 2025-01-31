
#include <algorithm>
#include <vector>



#ifndef SPAN_HPP
#define SPAN_HPP

// alt + n = ~

class Span
{
	private:
		Span();
		unsigned int		N;
		std::vector<int>	container;

	public:
		~Span();
		Span(unsigned int size);
		Span(const Span& other);
		Span operator=(const Span& other);

		void addNumber(int number);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		void addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif

