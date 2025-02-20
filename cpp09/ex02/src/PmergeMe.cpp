




#include"../include/PmergeMe.hpp"

void 	PmergeMe::run(int argc, char** argv)
{
	if(parseInput(argc, argv))
		throw WrongInputException();
	fillContainer(argc, argv);
	sorting(this->_vector);
	// sorting(this->_deque);

}


int PmergeMe::parseInput(int argc, char** argv)
{
	int i = 1;
	std::string number;
	while (i < argc)
	{
		number = argv[i];
		for (char c : number)
		{
			if(!isdigit(c))
				return 1;
		}
		i++;		
	}
	std::cout << "Input is Numbers only" << std::endl;
	return 0;
}

template <typename T> void PmergeMe::printContainer(const T& ref) const
{
	for (int x : ref)
		std::cout << x << " ";
	std::cout << "\n";
	return ;
}


template <typename T>	
void PmergeMe::printIterators(const std::string message, typename T::iterator StartIt, typename T::iterator EndIt) const
{
	std::cout << message << "\n"	
	<< "BlockStartIt		" << &(*StartIt)	<< " " << *(StartIt)	<< '\n'
	<< "BlockEndIt		" << &(*EndIt)	<< " " << *(EndIt)	<< "\n\n";
}


void PmergeMe::fillContainer(int argc, char** argv)
{
	int i = 1;
	while(i < argc)
	{
		// std::cout << "[-> " << atoi(argv[i]) << " <-]" << std::endl;
		_vector.push_back(atoi(argv[i]));
		// _deque.push_back(atoi(argv[i]));
		i++;
	}
	printContainer(_vector);
	// printContainer(_deque);
}


template <typename T> void PmergeMe::sorting(T& ref)
{
	this->_compareCounter = 0;
	this->_levelOfRecursion = 0;
	// auto start = std::chrono::high_resolution_clock::now();
	pairing(ref, 1);
	// auto stop = std::chrono::high_resolution_clock::now();
	// auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// std::cout << "Time to execute : " << duration.count() << " microseconds" << std::endl;
	// std::cout << "Compares : " << this->_compareCounter << std::endl;
}



template <typename T> 
void 	PmergeMe::sortToPairs(typename T::iterator startIt, typename T::iterator endIt, size_t amountOfBlocks)
{
	auto newIt = startIt;
	while (newIt != endIt)
	{
		printContainer(this->_vector);
		if(amountOfBlocks * 2 == 2)
		{
			// std::cout << "Update Iterators 2\n";
			auto BlockOneStartIt = newIt;
			auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfBlocks);
			printIterators<T>("Before ONE", BlockOneStartIt, BlockOneEndIt);
			if(*BlockOneStartIt > *BlockOneEndIt)
			{
				// std::cout << "Swap " << *BlockOneStartIt << " > " << *BlockOneEndIt << std::endl;
				std::iter_swap(BlockOneStartIt, BlockOneEndIt);
			}
			_compareCounter++;
			printIterators<T>("After ONE", BlockOneStartIt, BlockOneEndIt);
		}
		else
		{
			// std::cout << "Update Iterators\n";
			auto BlockOneStartIt = newIt;
			auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfBlocks - 1);
			auto BlockTwoStartIt = std::next(BlockOneStartIt, amountOfBlocks);
			auto BlockTwoEndIt = std::next(BlockTwoStartIt, amountOfBlocks - 1);
		
			printIterators<T>("Before ONE", BlockOneStartIt, BlockOneEndIt);
			printIterators<T>("Before TWO", BlockTwoStartIt, BlockTwoEndIt);

			if (BlockTwoStartIt >= endIt || BlockTwoEndIt > endIt) 
			{
				// std::cout << "break\n";
				break;
			}
			// std::cout << "no break\n";
			// std::cout << "Comparison " << *BlockOneEndIt << " > " << *BlockTwoEndIt << std::endl;
			if(*BlockOneEndIt > *BlockTwoEndIt)
			{
				// std::cout << "Swap " << *BlockOneEndIt << " > " << *BlockTwoEndIt << std::endl;
				std::swap_ranges(BlockOneStartIt, BlockTwoStartIt, BlockTwoStartIt);
			}
			_compareCounter++;
			printIterators<T>("After ONE", BlockOneStartIt, BlockOneEndIt);
			printIterators<T>("After TWO", BlockTwoStartIt, BlockTwoEndIt);
		}		
		std::advance(newIt, 2 * amountOfBlocks);
	}
}

unsigned long long PmergeMe::jakobsthal_recursive(int n) 
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jakobsthal_recursive(n - 1) + 2 * jakobsthal_recursive(n - 2);
}

template <typename T> void PmergeMe::sortWithInsertion(T& ref,size_t nbrsInBlock, int amountOfBlocks)
{

	std::cout << "sortWithInsertion" << std::endl;
	std::cout << "amountOfBlocks " << amountOfBlocks << " - nbrsInBlock " << nbrsInBlock << std::endl;
	if(nbrsInBlock <= 2) // if numbers in block is 2 or less no compare necessary because already sorted in sortToPairs
	{
		std::cout << GREEN << "Block of 2 already sorted in sortToPairs" << RESET << std::endl;
		return;
	}
	ref.size();
	


	// TO-DO
	// temp container pend with bs starting at b2
	// jakobszahl 1 ist 3. mit 
	// 
	// printContainer(ref);
	// auto newIt = ref.begin();
	// auto BlockOneStartIt = newIt;
	// auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfBlocks - 1);
	// auto BlockTwoStartIt = std::next(BlockOneStartIt, amountOfBlocks);
	// auto BlockTwoEndIt = std::next(BlockTwoStartIt, amountOfBlocks - 1);
	// printIterators<T>("Before ONE", BlockOneStartIt, BlockOneEndIt);
	// printIterators<T>("Before TWO", BlockTwoStartIt, BlockTwoEndIt);
}


template <typename T> void PmergeMe::pairing(T& ref, int amountOfBlocks)
{
	size_t nbrsInBlock = ref.size() / amountOfBlocks;
	if(nbrsInBlock < 2)
		return;
	this->_levelOfRecursion++;
	std::cout << RED << "_levelOfRecursion " << _levelOfRecursion << RESET << std::endl;
	// std::cout << "amountOfBlocks " << amountOfBlocks << std::endl;
	// get Start and End Iterator
	auto startIt = ref.begin();
	auto endIt = std::next(startIt, amountOfBlocks * nbrsInBlock);
	if (nbrsInBlock % 2 == 1) 
	endIt = std::next(startIt, amountOfBlocks * (nbrsInBlock - 1));
	
	sortToPairs<T>(startIt, endIt, amountOfBlocks);
	pairing(ref, amountOfBlocks * 2);
	printContainer<T>(ref);
	this->_levelOfRecursion--;
	std::cout << RED << "_levelOfRecursion " << _levelOfRecursion << RESET << std::endl;
	sortWithInsertion(ref, nbrsInBlock, amountOfBlocks);
}











/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* PmergeMe::WrongInputException::what() const noexcept
{
	return "PmergeMe Wrong Input";
}