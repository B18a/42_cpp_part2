


#include <vector>
#include <deque>

#include <iostream>
#include <exception>
#include <chrono>


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		int					_compareCounter;
		int					_jakobNumber;
		int					_jakobNumberOld;
		int					_jakobNumberIdx;
		size_t				_levelOfRecursion;
		size_t				_SizeOfGroup;
		int				_bCounter;
	


	public:
		void 	run(int argc, char** argv);
		int 	parseInput(int argc, char** argv);
		void	fillContainer(int argc, char** argv);

		unsigned long long	jakobsthal_recursive(int n);

		template <typename T>	void printContainer(const T& original, int seperator) const;
		template <typename T>	void printIterators(const std::string message, typename T::iterator StartIt, typename T::iterator EndIt) const;

		template <typename T>	void sorting(T& original);
		template <typename T>	void pairing(T& original, size_t amountOfElements);
		template <typename T>	void sortToPairs(typename T::iterator startIt, typename T::iterator endIt, size_t amountOfElements, size_t nbrsInElement);
		template <typename T>	void sortWithInsertion(T& original, size_t nbrsInEachGroup, size_t amountOfGroups);
		template <typename T>	void retrySorting(T& original);
		template <typename T>	typename T::iterator fillMainBlockWise(typename T::iterator startIt, T& main, T& original, size_t amountOfGroups);
		template <typename T>	void extraordinarySorting(T& main, T& original);
		template <typename T>	void fillOddContainer(T& odd, T& original, T& main);
		template <typename T>	void fillRestContainer(T& rest ,T& odd, T& original, T& main);
		template <typename T>	void fillPendContainer(T& pend, T& main);
		template <typename T>	void fillMainContainerWithPend(T& pend, T& main);
		template <typename T>	void fillMainContainerWithOdd(T& odd, T& main);
		template <typename T>	void fillMainContainerWithRest(T& rest, T& main);
		template <typename T>	void printFillContainers(T& rest ,T& odd, T& original, T& main);


		template <typename T>	bool validateIterator(typename T::iterator BeginIt, typename T::iterator EndIt, size_t position);
		template <typename T>	void first(T& main, T& rest, T& odd, T& pend);


		class WrongInputException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};

#endif




/****************************************/
/*			Text Colors 				*/
/****************************************/

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define DEFAULT "\033[39m"
#define RESET   "\033[0m" 


#define BOLD      "\033[1m"
#define DIM       "\033[2m"
#define ITALIC    "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[5m"
#define REVERSE   "\033[7m"  // Invert foreground & background
#define HIDDEN    "\033[8m"  // Hidden text
#define STRIKE    "\033[9m"  // Strikethrough


#define BG_BRIGHT_BLACK   "\033[100m"
#define BG_BRIGHT_RED     "\033[101m"
#define BG_BRIGHT_GREEN   "\033[102m"
#define BG_BRIGHT_YELLOW  "\033[103m"
#define BG_BRIGHT_BLUE    "\033[104m"
#define BG_BRIGHT_MAGENTA "\033[105m"
#define BG_BRIGHT_CYAN    "\033[106m"
#define BG_BRIGHT_WHITE   "\033[107m"

#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"
#define BG_DEFAULT "\033[49m"
