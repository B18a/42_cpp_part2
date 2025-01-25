

// alt + n = ~

class Span
{
	private:
		unsigned int N;
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



