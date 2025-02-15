


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
		int					_compareCounter;	// setting to 0 in

	public:
		void 	run(int argc, char** argv);
		int 	parseInput(int argc, char** argv);
		void	fillContainer(int argc, char** argv);
		
		template <typename T>	void printContainer(const T& ref) const;
		template <typename T>	void printIterators(const std::string message, typename T::iterator StartIt, typename T::iterator EndIt) const;

		template <typename T>	void sorting(T& ref);
		template <typename T>	void pairing(T& ref, int blockSize);
		template <typename T>	void sortToPairs(typename T::iterator startIt, typename T::iterator endIt, size_t blockSize);





		class WrongInputException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};

#endif