


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
		size_t				_levelOfRecursion;

	public:
		void 	run(int argc, char** argv);
		int 	parseInput(int argc, char** argv);
		void	fillContainer(int argc, char** argv);
		
		template <typename T>	void printContainer(const T& ref) const;
		template <typename T>	void printIterators(const std::string message, typename T::iterator StartIt, typename T::iterator EndIt) const;

		template <typename T>	void sorting(T& ref);
		template <typename T>	void pairing(T& ref, int amountOfBlocks);
		template <typename T>	void sortToPairs(typename T::iterator startIt, typename T::iterator endIt, size_t amountOfBlocks);
		template <typename T>	void sortWithInsertion(T& ref,size_t nbrsInBlock, int amountOfBlocks);





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