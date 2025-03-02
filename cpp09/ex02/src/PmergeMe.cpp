




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
	T main;
	this->_compareCounter = 0;
	this->_levelOfRecursion = 0;
	this->_jakobNumber = 1;
	this->_jakobNumberOld = 1;
	this->_jakobNumberIdx = 2;
	this->_SizeOfGroup = 1;
	this->_bCounter = 0;
	// auto start = std::chrono::high_resolution_clock::now();
	pairing(original, 1);
	// auto stop = std::chrono::high_resolution_clock::now();
	// auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// std::cout << "Time to execute : " << duration.count() << " microseconds" << std::endl;
	// std::cout << "Compares : " << this->_compareCounter << std::endl;

	std::cout << CYAN << "Main Container" << RESET << std::endl;
	printContainer<T>(main, 0);
	std::cout << BG_CYAN << "_compareCounter " << this->_compareCounter << RESET << std::endl;

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
		
			printIterators<T>("Before ONE", BlockOneStartIt, BlockOneEndIt);
			printIterators<T>("Before TWO", BlockTwoStartIt, BlockTwoEndIt);

			// if (BlockTwoStartIt >= endIt || BlockTwoEndIt > endIt) // or line below?!?!? 
			if (BlockTwoStartIt >= endIt || BlockTwoEndIt > endIt || nbrsInEachGroup <= 2) 
			{
				std::cout << RED << "              break\n" << RESET;
				this->_SizeOfGroup = this->_SizeOfGroup / 2;
				break;
			}
			std::cout << RED << "                  no break\n" << RESET;
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
		std::advance(newIt, 2 * amountOfGroups);
	}
}

unsigned long long PmergeMe::jakobsthal_recursive(int n) 
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jakobsthal_recursive(n - 1) + 2 * jakobsthal_recursive(n - 2);
}




template <typename T> typename T::iterator PmergeMe::sortFirstTwoPairsToMain(typename T::iterator startIt, T& main, T& original, size_t amountOfGroups)
{

	std::cout << BG_MAGENTA << "sortFirstTwoPairsToMain" << RESET << std::endl;


	auto BlockOneStartIt = startIt; // StartIt - Start Element of Group
	auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfGroups); //EndIt - Content of End Iterator is NOT included in Group
	auto BlockTwoStartIt = std::next(BlockOneStartIt, amountOfGroups); // StartIt - Start Element of Group
	auto BlockTwoEndIt = std::next(BlockTwoStartIt, amountOfGroups); //EndIt - Content of End Iterator is NOT included in Group

	auto BlockOneLastIt = std::prev(BlockOneEndIt); // LastIt - Contains Last Element of Group
	auto BlockTwoLastIt = std::prev(BlockTwoEndIt); // LastIt - Contains Last Element of Group

	printIterators<T>("First Pair	", BlockOneStartIt, BlockOneEndIt);
	printIterators<T>("Second Pair	", BlockTwoStartIt, BlockTwoEndIt);
	printIterators<T>("BlockLastIt	", BlockOneLastIt, BlockTwoLastIt);

	// (void)nbrsInEachGroup;

	// if(*BlockOneLastIt > *BlockTwoLastIt)
	// {
	// 	std::cout << *BlockOneLastIt << " > > >" << *BlockTwoLastIt << std::endl;
	// 	main.insert(main.end(),BlockTwoStartIt, std::next(BlockTwoLastIt));
	// 	main.insert(main.end(), BlockOneStartIt, std::next(BlockOneLastIt));
	// }
	// else
	// {
		// std::cout << *BlockOneLastIt << " < < < " << *BlockTwoLastIt << std::endl;
		main.insert(main.end(),BlockOneStartIt, std::next(BlockOneLastIt));
		main.insert(main.end() ,BlockTwoStartIt, std::next(BlockTwoLastIt));
	// }
	// this->_compareCounter++;
	std::cout << MAGENTA << "main container" << RESET << std::endl;
	printContainer(main, 0);
	std::cout << MAGENTA << "original container" << RESET << std::endl;
	printContainer(original, 0);


	std::cout << BG_MAGENTA << "sortFirstTwoPairsToMain END" << RESET << std::endl;
	return BlockTwoEndIt;

}


template <typename T> void PmergeMe::fillOddContainer(T& odd, T& original, T& main)
{
	auto ItIterOriginal = std::next(original.begin(), main.size());
	auto EndItOriginal = std::next(ItIterOriginal, this->_SizeOfGroup);

	printIterators<T>("ItIter <-> EndItOriginal	", ItIterOriginal, EndItOriginal);

	odd.insert(odd.end(), ItIterOriginal, EndItOriginal);
}

template <typename T> void PmergeMe::fillRestContainer(T& rest ,T& odd, T& original, T& main)
{
	auto ItIterOriginal = std::next(original.begin(), (main.size() + odd.size()));
	auto EndItOriginal = original.end();

	printIterators<T>("ItIter <-> EndItOriginal	", ItIterOriginal, EndItOriginal);

	rest.insert(rest.end(), ItIterOriginal, EndItOriginal);
}

template <typename T> void PmergeMe::fillPendContainer(T& pend, T& main)
{
	std::cout << GREEN << "take all bs and set it to pend" << RESET << std::endl;

	// auto StartMainIt = main.begin();
	auto StartMainIt = std::next(main.begin(), this->_SizeOfGroup * 2);
	auto EndMainIt = std::next(StartMainIt, this->_SizeOfGroup);

	int iteration = 0;

	while (EndMainIt != main.end())
	{  

		if (iteration % 2 == 0)  // Send to pend on every second iteration
		{
			std::cout << "INSERTING TO PEND" << std::endl;
			pend.insert(pend.end(), StartMainIt, EndMainIt);
			StartMainIt = main.erase(StartMainIt, EndMainIt); // Update StartMainIt to new position
		}
		else
		{
			std::advance(StartMainIt, this->_SizeOfGroup);
		}

		if (StartMainIt == main.end()) break;

		EndMainIt = std::next(StartMainIt, this->_SizeOfGroup);
		if (EndMainIt > main.end()) 
			EndMainIt = main.end();

		iteration++;
	}
}

template <typename T>	void PmergeMe::printFillContainers(T& pend ,T& odd, T& rest, T& main)
{
	std::cout << MAGENTA << "P E N D Container" << RESET << std::endl;
	printContainer(pend, 0);
	std::cout << MAGENTA << "O D D Container" << RESET << std::endl;
	printContainer(odd, 0);
	std::cout << MAGENTA << "R E S T Container" << RESET << std::endl;
	printContainer(rest, 0);
	std::cout << MAGENTA << "M A I N Container" << RESET << std::endl;
	printContainer(main, 0);
}



template <typename T>	void PmergeMe::fillMainContainerWithOdd(T& odd, T& main)
{
	std::cout << BG_BLUE << "fillMainContainerWithOdd" << RESET << std::endl;
	auto OddStart = odd.begin();
	auto OddEnd = odd.end();
	auto Oddlast = std::prev(OddEnd);

	auto PrevEnd = std::next(main.begin(), this->_SizeOfGroup);
	auto MainStart = main.begin();

	int i = 0;

	while(odd.size())
	{
		MainStart = std::next(main.begin(), this->_SizeOfGroup * i);
		auto MainEnd = std::next(MainStart, this->_SizeOfGroup);
		auto MainLastNbr = std::prev(MainEnd);


		std::cout << "*Oddlast < *MainLastNbr "<< *Oddlast << " < " << *MainLastNbr << std::endl;

		this->_compareCounter++;
		if(*Oddlast <= *MainLastNbr)
		{
			main.insert(PrevEnd, OddStart, OddEnd);
			// std::cout << MAGENTA << "Odd Container" << RESET << std::endl;
			// printContainer(odd, 0);

			odd.erase(OddStart, OddEnd);

			// std::cout << MAGENTA << "Odd Container" << RESET << std::endl;
			// printContainer(odd, 0);
			// std::cout <<"------> Odd is inserted to main" << std::endl;
		}	
		PrevEnd = MainEnd;
		i++;
	}
	std::cout << BG_BLUE << "fillMainContainerWithPenOdd END" << RESET << std::endl;
}


template <typename T>	void PmergeMe::fillMainContainerWithRest(T& rest, T& main)
{
	std::cout << BG_CYAN << "fillMainContainerWithRest" << RESET << std::endl;

	auto RestStart = rest.begin();
	auto RestEnd = rest.end();
		
	main.insert(main.end(), RestStart, RestEnd);
	rest.erase(RestStart, RestEnd);

	std::cout << BG_CYAN << "fillMainContainerWithRest END" << RESET << std::endl;
}


template <typename T> void PmergeMe::fillingMain(T& main, T& original)
{
	std::cout << UNDERLINE << RED << "fillingMain" << RESET << std::endl;
	std::cout << CYAN << "this->_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;
	
	size_t lengthMain = main.size();
	size_t lengthOriginal = original.size();

	size_t diff = lengthOriginal - lengthMain;

	std::cout << GREEN << "diff " << diff << std::endl;

	// not enough elements to fit in the size of group so fill it up to main
	if(diff < this->_SizeOfGroup)
	{
		std::cout << YELLOW << "Rest is too small for a group so fill it up" << RESET << std::endl;
		auto ItIter = std::next(original.begin(), main.size());
		auto EndItOriginal = original.end();

		printIterators<T>("ItIter <-> EndItOriginal	", ItIter, EndItOriginal);

		main.insert(main.end(),ItIter, EndItOriginal);
	}
	else
	{
		T pend;
		T odd;
		T rest;

		// at least once there are enough elements to fit in a group so put these elements to odd container
		std::cout << YELLOW << "HERE COMES THE ODD PART" << RESET << std::endl;
		//  get start and end Iterator of rest that fits in the current groupsize
		fillOddContainer(odd, original, main);
		fillRestContainer(rest, odd, original, main);
		fillPendContainer(pend, main);

	printFillContainers(pend , odd,  rest,main);
		fillMainContainerWithPend(pend, main);
		pend.erase(pend.begin(), pend.end());
	printFillContainers(pend , odd,  rest,main);
		fillMainContainerWithOdd(odd, main);
	printFillContainers(pend , odd,  rest,main);
		fillMainContainerWithRest(rest, main);		
	printFillContainers(pend , odd,  rest,main);
	}

	// std::cout << MAGENTA << "main container" << RESET << std::endl;
	// printContainer(main, 0);
	std::cout << UNDERLINE << RED << "fillingMain done" << RESET << std::endl;
}



template <typename T> void PmergeMe::fillMainContainerWithPend(T& pend, T& main)
{
	std::cout << BG_GREEN << "fillMainContainerWithPend" << RESET << std::endl;


	// this->_jakobNumberIdx = 2;
	// this->_jakobNumber = 1;

	// int jakob[] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
	// int	idx = 2;
	int insertions = 0;

	// std::cout << YELLOW << "JakobIDX " << this->_jakobNumberIdx << ":" << this->_jakobNumber << " old " << this->_jakobNumberOld << RESET << std::endl;

	size_t size = pend.size();

	while(size)
	{
		auto PendStart = pend.begin();
		
		//if there are more elements in pend and not only one the start of the insertion must be calculated due to jakob
		if((pend.size() / this->_SizeOfGroup) != 1) 
		PendStart = std::next(pend.begin(), this->_SizeOfGroup * (insertions));
		
		auto PendEnd = std::next(PendStart, this->_SizeOfGroup);
		auto PendLastNbr = std::prev(PendEnd);


		// Not needed !?!?!
		if (PendEnd != pend.end()) {
			std::cout << BG_BRIGHT_RED << "PEND " << "Start " << *PendStart << " Last " << *PendLastNbr << " End " << *PendEnd << RESET << std::endl;
		} else {
			std::cout << "PEND reached end of container!" << std::endl;
			std::cout << BG_BRIGHT_RED << "PEND " << "Start " << *PendStart << " Last " << *PendLastNbr << " End " << *PendEnd << RESET << std::endl;
		}


		auto MainStart = main.begin();
		while(MainStart != main.end())
		{
			auto MainEnd = std::next(MainStart, this->_SizeOfGroup);
			auto MainLastNbr = std::prev(MainEnd);

			this->_compareCounter++;

			if(*PendLastNbr <= *MainLastNbr)
			{
				main.insert(MainStart, PendStart, PendEnd);
				std::cout <<"------> Pend is inserted to main" << std::endl;
				std::cout << CYAN << "main CONTAINER after insertion" << RESET << std::endl;
				printContainer(main, 0);
				insertions++;
				size -= this->_SizeOfGroup;
				break;
			}
			std::advance(MainStart, this->_SizeOfGroup);
		}
	}
	std::cout << BG_GREEN << "fillMainContainerWithPend END" << RESET << std::endl;
}


template <typename T> void PmergeMe::sortWithInsertion(T& original, size_t nbrsInEachGroup, size_t amountOfGroups)
{
	std::cout << "amountOfGroups " << amountOfGroups << CYAN << " - nbrsInEachGroup " << nbrsInEachGroup << RESET << std::endl;
	std::cout << CYAN << "this->_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;

	// if(nbrsInEachGroup <= 2) // if numbers in block is 2 or less no compare necessary because already sorted in sortToPairs
	// if(this->_SizeOfGroup <= 2) // if numbers in block is 2 or less no compare necessary because already sorted in sortToPairs
	// {
	// 	std::cout << GREEN << "Group of 2 already sorted in sortToPairs" << RESET << std::endl;
	// 	return;
	// }
	
	T main;


		// issue
		// 				|
		// 				v

	auto iter = original.begin();
	for ( size_t i = 0; i < nbrsInEachGroup / 2; i++)
	{
		iter = sortFirstTwoPairsToMain(iter, main, original, amountOfGroups);
	}

	if(std::prev(original.end()) != std::prev(main.end()))
		fillingMain(main, original);



	original = main; //delete original ?? valgrind?!?!
	// 	// Update the main sequence of elements
	// std::copy( mainChain.begin(), mainChain.end(), data.begin() );
}


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


	std::cout << GREEN << "------------------------ PAIRING DONE ------------------------" << RESET << std::endl;
	std::cout << MAGENTA << "original container" << RESET << std::endl;
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





// 2 11 0 16 6 15 8 17 9 18 14 19 3 10 1 21 5 12 4 20 7 13 
// 2 11 0 16 6 15 8 17 9 18 14 19 5 12 4 20 3 10 1 21 7 13

// ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7