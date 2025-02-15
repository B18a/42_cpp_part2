




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
	auto start = std::chrono::high_resolution_clock::now();
	pairing(ref, 1);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time to execute : " << duration.count() << " microseconds" << std::endl;
	std::cout << "Compares : " << this->_compareCounter << std::endl;
}



template <typename T> 
void 	PmergeMe::sortToPairs(typename T::iterator startIt, typename T::iterator endIt, size_t blockSize)
{
	auto newIt = startIt;
	while (newIt != endIt)
	{
		printContainer(this->_vector);
		if(blockSize * 2 == 2)
		{
			std::cout << "Update Iterators 2\n";
			auto BlockOneStartIt = newIt;
			auto BlockOneEndIt = std::next(BlockOneStartIt, blockSize);
			printIterators<T>("Before ONE", BlockOneStartIt, BlockOneEndIt);
			if(*BlockOneStartIt > *BlockOneEndIt)
			{
				std::cout << "Swap " << *BlockOneStartIt << " > " << *BlockOneEndIt << std::endl;
				std::iter_swap(BlockOneStartIt, BlockOneEndIt);
			}
			_compareCounter++;
			printIterators<T>("After ONE", BlockOneStartIt, BlockOneEndIt);
		}
		else
		{
			std::cout << "Update Iterators\n";
			auto BlockOneStartIt = newIt;
			auto BlockOneEndIt = std::next(BlockOneStartIt, blockSize - 1);
			auto BlockTwoStartIt = std::next(BlockOneStartIt, blockSize);
			auto BlockTwoEndIt = std::next(BlockTwoStartIt, blockSize - 1);
		
			printIterators<T>("Before ONE", BlockOneStartIt, BlockOneEndIt);
			printIterators<T>("Before TWO", BlockTwoStartIt, BlockTwoEndIt);

			if (BlockTwoStartIt >= endIt || BlockTwoEndIt > endIt) 
			{
				std::cout << "break\n";
				break;
			}
			std::cout << "no break\n";
			std::cout << "Comparison " << *BlockOneEndIt << " > " << *BlockTwoEndIt << std::endl;
			if(*BlockOneEndIt > *BlockTwoEndIt)
			{
				std::cout << "Swap " << *BlockOneEndIt << " > " << *BlockTwoEndIt << std::endl;
				std::swap_ranges(BlockOneStartIt, BlockTwoStartIt, BlockTwoStartIt);
			}
			_compareCounter++;
			printIterators<T>("After ONE", BlockOneStartIt, BlockOneEndIt);
			printIterators<T>("After TWO", BlockTwoStartIt, BlockTwoEndIt);
		}		
		std::advance(newIt, 2 * blockSize);
	}
}


template <typename T> void PmergeMe::pairing(T& ref, int blockSize)
{
	size_t blockSizeInBlock = ref.size() / blockSize;
	if(blockSizeInBlock < 2)
		return;
	// get Start and End Iterator
	auto startIt = ref.begin();
	auto endIt = std::next(startIt, blockSize * blockSizeInBlock);
	if (blockSizeInBlock % 2 == 1) 
    	endIt = std::next(startIt, blockSize * (blockSizeInBlock - 1));

	sortToPairs<T>(startIt, endIt, blockSize);
	printContainer<T>(ref);
	pairing(ref, blockSize * 2);
}











/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* PmergeMe::WrongInputException::what() const noexcept
{
	return "PmergeMe Wrong Input";
}