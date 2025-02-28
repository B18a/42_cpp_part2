




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

template <typename T> void PmergeMe::printContainer(const T& original, int seperator) const
{
	int y = 1;
	std::cout << "[";
	for (int x : original)
	{
		std::cout << x << " ";
		if(seperator != 0 && y % seperator == 0)
			std::cout << "][";
		y++;
	}
	std::cout << "]";
	std::cout << "\n";
	return ;
}


template <typename T>	
void PmergeMe::printIterators(const std::string message, typename T::iterator StartIt, typename T::iterator EndIt) const
{
	std::cout << BLUE << message << RESET << "\n"	
	<< "Iter One		" << &(*StartIt)	<< " " << *(StartIt)	<< '\n'
	<< "Iter Two		" << &(*EndIt)	<< " " << *(EndIt)	<< "\n\n";
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
	printContainer(_vector, 0);
	// printContainer(_deque, 0);
}


template <typename T> void PmergeMe::sorting(T& original)
{
	this->_compareCounter = 0;
	this->_levelOfRecursion = 0;
	this->_jakobNumber = 1;
	this->_jakobNumberIdx = 2;
	this->_SizeOfGroup = 1;
	// auto start = std::chrono::high_resolution_clock::now();
	pairing(original, 1);
	// auto stop = std::chrono::high_resolution_clock::now();
	// auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// std::cout << "Time to execute : " << duration.count() << " microseconds" << std::endl;
	// std::cout << "Compares : " << this->_compareCounter << std::endl;
}


// for first iteration we have 1 Group so we have to check groups of 2 nbrs (first if condition)
// all other iterations the nbrs in each group get mulitplied by 2: 2,4,8,16, and so on

template <typename T> 
void 	PmergeMe::sortToPairs(typename T::iterator startIt, typename T::iterator endIt, size_t amountOfGroups, size_t nbrsInEachGroup)
{
	auto newIt = startIt;
	while (newIt != endIt)
	{
		// if(amountOfGroups * 2 == 2)
		if(this->_SizeOfGroup == 2)
		{
			std::cout << CYAN << "ELEMENT OF TWO" << RESET << std::endl;
			// std::cout << CYAN << "ELEMENT OF TWO" << RESET << std::endl;
			// std::cout << "Update Iterators 2\n";
			auto BlockOneStartIt = newIt;
			auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfGroups);
			// printIterators<T>("Before ONE", BlockOneStartIt, BlockOneEndIt);
			if(*BlockOneStartIt > *BlockOneEndIt)
			{
				// std::cout << "Swap " << *BlockOneStartIt << " > " << *BlockOneEndIt << std::endl;
				std::iter_swap(BlockOneStartIt, BlockOneEndIt);
			}
			_compareCounter++;
			// printIterators<T>("After ONE", BlockOneStartIt, BlockOneEndIt);
		}
		else
		{
			std::cout << CYAN << "ELEMENT OF MULTIPLE" << RESET << std::endl;
			// std::cout << "Update Iterators\n";
			auto BlockOneStartIt = newIt;
			auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfGroups - 1);
			auto BlockTwoStartIt = std::next(BlockOneStartIt, amountOfGroups);
			auto BlockTwoEndIt = std::next(BlockTwoStartIt, amountOfGroups - 1);
		
			// printIterators<T>("Before ONE", BlockOneStartIt, BlockOneEndIt);
			// printIterators<T>("Before TWO", BlockTwoStartIt, BlockTwoEndIt);

			// if (BlockTwoStartIt >= endIt || BlockTwoEndIt > endIt) // or line below?!?!? 
			if (BlockTwoStartIt >= endIt || BlockTwoEndIt > endIt || nbrsInEachGroup <= 2) 
			{
				std::cout << RED << "              break\n" << RESET;
				this->_SizeOfGroup = this->_SizeOfGroup / 2;
				break;
			}
			std::cout << RED << "                  no break\n" << RESET;
			// std::cout << "Comparison " << *BlockOneEndIt << " > " << *BlockTwoEndIt << std::endl;
			if(*BlockOneEndIt > *BlockTwoEndIt)
			{
				// std::cout << "Swap " << *BlockOneEndIt << " > " << *BlockTwoEndIt << std::endl;
				std::swap_ranges(BlockOneStartIt, BlockTwoStartIt, BlockTwoStartIt);
			}
			_compareCounter++;
			// printIterators<T>("After ONE", BlockOneStartIt, BlockOneEndIt);
			// printIterators<T>("After TWO", BlockTwoStartIt, BlockTwoEndIt);
		}	
		std::advance(newIt, 2 * amountOfGroups);
	}
}

unsigned long long PmergeMe::jakobsthal_recursive(int n) 
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jakobsthal_recursive(n - 1) + 2 * jakobsthal_recursive(n - 2);
}




template <typename T> typename T::iterator PmergeMe::sortFirstTwoPairsToMain(typename T::iterator startIt, T& main, T& original, size_t nbrsInEachGroup, size_t amountOfGroups)
{
	auto BlockOneStartIt = startIt; // StartIt - Start Element of Group
	auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfGroups); //EndIt - Content of End Iterator is NOT included in Group
	auto BlockTwoStartIt = std::next(BlockOneStartIt, amountOfGroups); // StartIt - Start Element of Group
	auto BlockTwoEndIt = std::next(BlockTwoStartIt, amountOfGroups); //EndIt - Content of End Iterator is NOT included in Group

	auto BlockOneLastIt = std::prev(BlockOneEndIt); // LastIt - Contains Last Element of Group
	auto BlockTwoLastIt = std::prev(BlockTwoEndIt); // LastIt - Contains Last Element of Group

	printIterators<T>("First Pair	", BlockOneStartIt, BlockOneEndIt);
	printIterators<T>("Second Pair	", BlockTwoStartIt, BlockTwoEndIt);
	printIterators<T>("BlockLastIt	", BlockOneLastIt, BlockTwoLastIt);

	(void)nbrsInEachGroup;

	if(*BlockOneLastIt > *BlockTwoLastIt)
	{
		std::cout << *BlockOneLastIt << " > " << *BlockTwoLastIt << std::endl;
		main.insert(main.end(),BlockTwoStartIt, std::next(BlockTwoLastIt));
		main.insert(main.end(), BlockOneStartIt, std::next(BlockOneLastIt));
	}
	else
	{
		std::cout << *BlockOneLastIt << " < " << *BlockTwoLastIt << std::endl;
		main.insert(main.end(),BlockOneStartIt, std::next(BlockOneLastIt));
		main.insert(main.end() ,BlockTwoStartIt, std::next(BlockTwoLastIt));
	}
	std::cout << MAGENTA << "main container" << RESET << std::endl;
	printContainer(main, 0);
	std::cout << MAGENTA << "original container" << RESET << std::endl;
	printContainer(original, 0);

	return BlockTwoEndIt;

}



template <typename T> void PmergeMe::fillMainWithRest(T& main, T& original)
{
	std::cout << UNDERLINE << RED << "fillMainWithRest" << RESET << std::endl;

	auto ItIter = std::next(original.begin(), main.size());
	auto EndItOriginal = original.end();

	printIterators<T>("ItIter <-> EndItOriginal	", ItIter, EndItOriginal);

	main.insert(main.end(),ItIter, EndItOriginal);


	printContainer(main, 0);
	std::cout << UNDERLINE << RED << "fillMainWithRest done" << RESET << std::endl;
}
		



template <typename T> void PmergeMe::sortWithInsertion(T& original, size_t nbrsInEachGroup, size_t amountOfGroups)
{
	std::cout << "amountOfGroups " << amountOfGroups << CYAN << " - nbrsInEachGroup " << nbrsInEachGroup << RESET << std::endl;
	std::cout << CYAN << "this->_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;

	// if(nbrsInEachGroup <= 2) // if numbers in block is 2 or less no compare necessary because already sorted in sortToPairs
	if(this->_SizeOfGroup <= 2) // if numbers in block is 2 or less no compare necessary because already sorted in sortToPairs
	{
		std::cout << GREEN << "Group of 2 already sorted in sortToPairs" << RESET << std::endl;
		return;
	}
	this->_jakobNumber = jakobsthal_recursive(this->_jakobNumberIdx);
	std::cout << YELLOW << "JakobIDX " << this->_jakobNumberIdx << ":" << this->_jakobNumber << RESET << std::endl;
	
	
	T main;
	T pend;
	T odd;

	auto iter = original.begin();
	for ( size_t i = 0; i < nbrsInEachGroup / 2; i++ )
	{
		iter = sortFirstTwoPairsToMain(iter, main, original, nbrsInEachGroup, amountOfGroups);
		// std::cout << nbrsInEachGroup/2 << "-------------------------------------->" << i << std::endl;
	}
	// std::cout << "tttttttttttttttttttttttttttttttttttttttttttt " << original.size() - main.size() << std::endl;
	if(std::prev(original.end()) != std::prev(main.end()))
		fillMainWithRest(main, original);
	original = main;

	// printContainer(pend, amountOfGroups);
	printContainer(pend, this->_SizeOfGroup);
	
	this->_jakobNumberIdx++;
}

// bool isPowerOfTwo(int n) {
//     return (n > 0) && ((n & (n - 1)) == 0);
// }


template <typename T> void PmergeMe::pairing(T& original, size_t amountOfGroups)
{
	size_t nbrsInEachGroup = original.size() / amountOfGroups;
	if(nbrsInEachGroup < 2)
		return;
	
	this->_SizeOfGroup = this->_SizeOfGroup * 2;
	this->_levelOfRecursion++;
	// std::cout << RED << "_levelOfRecursion " << _levelOfRecursion << RESET << std::endl;
	std::cout << "amountOfGroups " << amountOfGroups << CYAN << " - nbrsInEachGroup " << nbrsInEachGroup << RESET << std::endl;


	// Get start and end Iterator of each Group depending on the size of the Group
	auto startIt = original.begin();
	auto endIt = std::next(startIt, amountOfGroups * nbrsInEachGroup);
	if (nbrsInEachGroup % 2 == 1) 
	endIt = std::next(startIt, amountOfGroups * (nbrsInEachGroup - 1));


	std::cout << YELLOW << "-----------------------------------------" << RESET << std::endl;

	std::cout << CYAN << "this->_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;
	sortToPairs<T>(startIt, endIt, amountOfGroups, nbrsInEachGroup);
	pairing(original, amountOfGroups * 2);

	std::cout << GREEN << "-------- PAIRING DONE --------" << RESET << std::endl;
	printContainer<T>(original, amountOfGroups);



	std::cout << RED << "Start sortWithInsertion " << "_levelOfRecursion " << _levelOfRecursion << RESET << std::endl;
	sortWithInsertion(original, nbrsInEachGroup, amountOfGroups);
	this->_levelOfRecursion--;
	this->_SizeOfGroup = this->_SizeOfGroup / 2;
}











/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* PmergeMe::WrongInputException::what() const noexcept
{
	return "PmergeMe Wrong Input";
}