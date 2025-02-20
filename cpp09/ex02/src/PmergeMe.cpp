




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
	std::cout << BLUE << message << RESET << "\n"	
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
	this->_jakobNumber = 1;
	this->_jakobNumberIdx = 1;
	// auto start = std::chrono::high_resolution_clock::now();
	pairing(ref, 1);
	// auto stop = std::chrono::high_resolution_clock::now();
	// auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// std::cout << "Time to execute : " << duration.count() << " microseconds" << std::endl;
	// std::cout << "Compares : " << this->_compareCounter << std::endl;
}



template <typename T> 
void 	PmergeMe::sortToPairs(typename T::iterator startIt, typename T::iterator endIt, size_t amountOfElements)
{
	auto newIt = startIt;
	while (newIt != endIt)
	{
		printContainer(this->_vector);
		if(amountOfElements * 2 == 2)
		{
			// std::cout << "Update Iterators 2\n";
			auto BlockOneStartIt = newIt;
			auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfElements);
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
			auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfElements - 1);
			auto BlockTwoStartIt = std::next(BlockOneStartIt, amountOfElements);
			auto BlockTwoEndIt = std::next(BlockTwoStartIt, amountOfElements - 1);
		
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
		std::advance(newIt, 2 * amountOfElements);
	}
}

unsigned long long PmergeMe::jakobsthal_recursive(int n) 
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jakobsthal_recursive(n - 1) + 2 * jakobsthal_recursive(n - 2);
}

template <typename T> void PmergeMe::sortWithInsertion(T& ref,size_t nbrsInElement, size_t amountOfElements)
{

	std::cout << "sortWithInsertion" << std::endl;
	std::cout << "amountOfElements " << amountOfElements << " - nbrsInElement " << nbrsInElement << std::endl;
	if(nbrsInElement <= 2) // if numbers in block is 2 or less no compare necessary because already sorted in sortToPairs
	{
		std::cout << GREEN << "Block of 2 already sorted in sortToPairs" << RESET << std::endl;
		return;
	}
	ref.size();
	this->_jakobNumber = jakobsthal_recursive(this->_jakobNumberIdx);
	std::cout << "JakobIDX " << this->_jakobNumber << ":" << this->_jakobNumber << std::endl;
	
	// TO-DO
	// temp container pend with bs starting at b2
	// 
	// T pend;
	// auto newIt = ref.begin();
	auto BlockJakobStartIt = ref.begin();
	auto BlockJakobEndIt = ref.begin();
	// printIterators<T>("BlockJakobStartIt", BlockJakobStartIt, BlockJakobEndIt);
	// if(this->_jakobNumber == 1)
	// {
		// std::cout << YELLOW << "_jakobNumber == 1" << RESET << std::endl;
		std::cout << YELLOW << _jakobNumber << RESET << std::endl;
		std::advance(BlockJakobStartIt, _jakobNumber * 2 * (nbrsInElement));
		BlockJakobEndIt = std::next(BlockJakobStartIt, nbrsInElement - 1);
	// }
	printIterators<T>("-->BlockJakobStartIt", BlockJakobStartIt, BlockJakobEndIt);
	// printContainer(ref);
	
	this->_jakobNumberIdx++;
}


template <typename T> void PmergeMe::pairing(T& ref, size_t amountOfElements)
{
	size_t nbrsInElement = ref.size() / amountOfElements;
	if(nbrsInElement % 2 != 0)
		nbrsInElement--;
	if(nbrsInElement < 2)
		return;
	this->_levelOfRecursion++;
	std::cout << RED << "_levelOfRecursion " << _levelOfRecursion << RESET << std::endl;
	std::cout << "amountOfElements " << amountOfElements << CYAN << " - nbrsInElement " << nbrsInElement << RESET << std::endl;
	// get Start and End Iterator
	auto startIt = ref.begin();
	auto endIt = std::next(startIt, amountOfElements * nbrsInElement);
	if (nbrsInElement % 2 == 1) 
	endIt = std::next(startIt, amountOfElements * (nbrsInElement - 1));
	
	sortToPairs<T>(startIt, endIt, amountOfElements);
	pairing(ref, amountOfElements * 2);
	printContainer<T>(ref);
	this->_levelOfRecursion--;
	std::cout << RED << "_levelOfRecursion " << _levelOfRecursion << RESET << std::endl;
	sortWithInsertion(ref, nbrsInElement, amountOfElements);
}











/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* PmergeMe::WrongInputException::what() const noexcept
{
	return "PmergeMe Wrong Input";
}