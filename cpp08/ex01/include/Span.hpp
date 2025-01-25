
#include <algorithm>
#include <array>
// HEADER PROTECTION!!!!!!

// alt + n = ~


template <typename T>
class Span
{
	private:
		unsigned int	N;
		std::vector<T>	container;

	public:
		Span();
		~Span();
		Span(unsigned int size);
		Span(const Span& other);
		Span operator=(const Span& other);

		void addNumber(void);
		void shortestSpan(void);
		void longestSpan(void);
};



