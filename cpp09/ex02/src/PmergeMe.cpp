




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
	// T main;
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
	printContainer<T>(original, 0);
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
			printIterators<T>("Before ONE", BlockOneStartIt, BlockOneEndIt);
			_compareCounter++;
			if(*BlockOneStartIt > *BlockOneEndIt)
			{
				// std::cout << "Swap " << *BlockOneStartIt << " > " << *BlockOneEndIt << std::endl;
				std::iter_swap(BlockOneStartIt, BlockOneEndIt);
			}
			printIterators<T>("After ONE", BlockOneStartIt, BlockOneEndIt);
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

			// if ( BlockTwoStartIt >= endIt || BlockTwoEndIt > endIt || nbrsInEachGroup <= 2) 
			(void)nbrsInEachGroup;
			if (BlockTwoStartIt >= endIt || BlockTwoEndIt > endIt) // or line below?!?!? 
			{
				std::cout << YELLOW << "              break\n" << RESET;
				this->_SizeOfGroup = this->_SizeOfGroup / 2;
				break;
			}
			std::cout << YELLOW << "                  no break\n" << RESET;
			std::cout << "Comparison " << *BlockOneEndIt << " > " << *BlockTwoEndIt << std::endl;
			_compareCounter++;
			if(*BlockOneEndIt > *BlockTwoEndIt)
			{
				std::cout << "Swap " << *BlockOneEndIt << " > " << *BlockTwoEndIt << std::endl;
				std::swap_ranges(BlockOneStartIt, BlockTwoStartIt, BlockTwoStartIt);
			}
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




template <typename T> typename T::iterator PmergeMe::fillMainBlockWise(typename T::iterator startIt, T& main, T& original, size_t amountOfGroups)
{

	std::cout << BG_MAGENTA << "fillMainBlockWise" << RESET << std::endl;


	auto BlockOneStartIt = startIt; // StartIt - Start Element of Group
	auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfGroups); //EndIt - Content of End Iterator is NOT included in Group
	auto BlockTwoStartIt = std::next(BlockOneStartIt, amountOfGroups); // StartIt - Start Element of Group
	auto BlockTwoEndIt = std::next(BlockTwoStartIt, amountOfGroups); //EndIt - Content of End Iterator is NOT included in Group

	auto BlockOneLastIt = std::prev(BlockOneEndIt); // LastIt - Contains Last Element of Group
	auto BlockTwoLastIt = std::prev(BlockTwoEndIt); // LastIt - Contains Last Element of Group

	printIterators<T>("First Pair	", BlockOneStartIt, BlockOneEndIt);
	printIterators<T>("Second Pair	", BlockTwoStartIt, BlockTwoEndIt);
	printIterators<T>("BlockLastIt	", BlockOneLastIt, BlockTwoLastIt);

	main.insert(main.end(),BlockOneStartIt, std::next(BlockOneLastIt));
	main.insert(main.end() ,BlockTwoStartIt, std::next(BlockTwoLastIt));

	std::cout << MAGENTA << "main container" << RESET << std::endl;
	printContainer(main, 0);
	std::cout << MAGENTA << "original container" << RESET << std::endl;
	printContainer(original, 0);


	std::cout << BG_MAGENTA << "fillMainBlockWise END" << RESET << std::endl;
	return BlockTwoEndIt;
	
}


template <typename T> void PmergeMe::fillOddContainer(T& odd, T& original, T& main)
{
	std::cout << BG_MAGENTA << "fillOddContainer" << RESET << std::endl;
	std::cout << BG_MAGENTA << "original size " << original.size() << " main size " << main.size()  << RESET << std::endl;
	std::cout << BG_MAGENTA << "this->_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;
	
	// if(original.size() - main.size() < this->_SizeOfGroup)
	// {
	// 	std::cout << BG_MAGENTA << "No full group available to fit in odd" << RESET << std::endl;
	// 	return;
	// }
	
	// check start and end iterator!?!?!?!?!?!?!??! for ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
	
	auto ItIterOriginal = std::next(original.begin(), main.size());
	auto EndItOriginal = std::next(ItIterOriginal, this->_SizeOfGroup);
	if(EndItOriginal > original.end())
	{
		return;
		// EndItOriginal = original.end();
	}
	std::cout << BG_MAGENTA << "ItIterOriginal == EndItOriginal" << RESET << std::endl;
	if(ItIterOriginal == EndItOriginal)
	{
		std::cout << BG_MAGENTA << "ItIterOriginal == EndItOriginal" << RESET << std::endl;
		return;
	}
	
	
	printIterators<T>("ItIterOriginal <-> EndItOriginal	", ItIterOriginal, EndItOriginal);
	
	std::cout << &(*original.end()) << " " << (*original.end()) << std::endl;
	if(ItIterOriginal == original.end())
		return;
	// Maybe!?!?!?
	if (ItIterOriginal < EndItOriginal)
	{
		odd.insert(odd.end(), ItIterOriginal, EndItOriginal);
	}
	else
	{
		std::cerr << "Skipping insert: No elements left to insert in ODD\n";
	}
	
	std::cout << BG_MAGENTA << "fillOddContainer END" << RESET << std::endl;
}

template <typename T> void PmergeMe::fillRestContainer(T& rest ,T& odd, T& original, T& main)
{
	auto ItIterOriginal = std::next(original.begin(), (main.size() + odd.size()));
	auto EndItOriginal = original.end();

	printIterators<T>("ItIter <-> EndItOriginal	", ItIterOriginal, EndItOriginal);

	std::cout << "Trying to insert from " 
		<< std::distance(original.begin(), ItIterOriginal) 
		<< " to " 
		<< std::distance(original.begin(), EndItOriginal) 
		<< std::endl;

	if (ItIterOriginal < EndItOriginal) {
		rest.insert(rest.end(), ItIterOriginal, EndItOriginal);
	} else {
		std::cerr << "Skipping insert: No elements left to insert in rest\n";
	}
}

template <typename T> void PmergeMe::fillPendContainer(T& pend, T& main)
{
	std::cout << GREEN << "take all bs and set it to pend" << RESET << std::endl;
	std::cout << BG_GREEN << "this->_SizeOfGroup " << RESET << this->_SizeOfGroup << std::endl;
	std::cout << BG_GREEN << "main.size() " << RESET << main.size() << std::endl;
	
	// auto StartMainIt = main.begin();
	int iteration = 0;
	auto StartMainIt = std::next(main.begin(), this->_SizeOfGroup * 2);
	auto EndMainIt = std::next(StartMainIt, this->_SizeOfGroup);
	
	printIterators<T>("bs", StartMainIt, EndMainIt);
	
	std::cout << BG_GREEN << "this->_SizeOfGroup <= main.size() " << this->_SizeOfGroup << " <= " << main.size()<< RESET << std::endl;
	if(this->_SizeOfGroup <= main.size())
	{
		std::cout << BG_GREEN << "return" << RESET << std::endl;
		return;
	}
	
	std::cout << BG_GREEN << "(EndMainIt != main.end())" << RESET << std::endl;
	while (EndMainIt != main.end())
	{  
		
		std::cout << BG_GREEN << "(iteration % 2 == 0)" << RESET << std::endl;
		if (iteration % 2 == 0)  // Send to pend on every second iteration
		{
			std::cout << BG_GREEN << "(iteration % 2 == 0)" << RESET << std::endl;
			std::cout << "INSERTING TO PEND" << std::endl;
			pend.insert(pend.end(), StartMainIt, EndMainIt);
			StartMainIt = main.erase(StartMainIt, EndMainIt); // Update StartMainIt to new position
		}
		else
		{
			std::cout << BG_GREEN << "else" << RESET << std::endl;
			std::advance(StartMainIt, this->_SizeOfGroup);
		}
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
		std::cout << BG_RED << "odd.size() " << odd.size() << RESET << std::endl;
		MainStart = std::next(main.begin(), this->_SizeOfGroup * i);
		auto MainEnd = std::next(MainStart, this->_SizeOfGroup);
		
		if(MainEnd > main.end())
		{
			
			std::cout << BG_RED << "main.insert(main.end(), OddStart, OddEnd);" << RESET << std::endl;
			main.insert(main.end(), OddStart, OddEnd);
			odd.erase(OddStart, OddEnd);
			return;
		}

		if(i == 0)
		{
			std::cout << BG_BLUE << "(i == 0)" << RESET << std::endl;
			MainStart = main.begin();
			MainEnd = std::next(MainStart, 1);
			PrevEnd = main.begin();
		}
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
	std::cout << BG_BLUE << "fillMainContainerWithOdd END" << RESET << std::endl;
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


template <typename T> void PmergeMe::extraordinarySorting(T& main, T& original)
{
	std::cout << UNDERLINE << YELLOW << "extraordinarySorting" << RESET << std::endl;
	std::cout << CYAN << "this->_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;
	
	size_t lengthMain = main.size();
	size_t lengthOriginal = original.size();

	size_t diff = lengthOriginal - lengthMain;

	std::cout << GREEN << "diff " << diff << std::endl;

	if(this->_SizeOfGroup == 2 && diff == 1)
	{
		T odd;
		
		std::cout << BG_YELLOW << "One is left" << RESET << std::endl;
		auto ItIter = std::next(original.begin(), main.size());
		auto EndItOriginal = original.end();
		odd.insert(odd.end(), ItIter, EndItOriginal);
		printIterators<T>("ItIter <-> EndItOriginal	", ItIter, EndItOriginal);
		
		fillMainContainerWithOdd(odd, main);
		std::cout << MAGENTA << "O D D Container" << RESET << std::endl;
		printContainer(odd, 0);
		std::cout << MAGENTA << "M A I N Container" << RESET << std::endl;
		printContainer(main, 0);
	}
	else
	{
		T pend;
		T odd;
		T rest;
		
	printFillContainers(pend , odd,  rest,main);
	
	// at least once there are enough elements to fit in a group so put these elements to odd container
	std::cout << YELLOW << "HERE COMES THE ODD PART" << RESET << std::endl;
	//  get start and end Iterator of rest that fits in the current groupsize
	printFillContainers(pend , odd,  rest,main);
	fillOddContainer(odd, original, main);
	printFillContainers(pend , odd,  rest,main);
	fillRestContainer(rest, odd, original, main);
	printFillContainers(pend , odd,  rest,main);
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
std::cout << UNDERLINE << YELLOW << "extraordinarySorting done" << RESET << std::endl;
}


template <typename T> bool PmergeMe::validateIterator(typename T::iterator BeginIt, typename T::iterator EndIt, size_t position)
{
	auto totalSizeIt = std::distance(BeginIt, EndIt);  // Total elements in main
	auto positionIt = position;  // Position we want to move to
	if (positionIt >= static_cast<size_t>(totalSizeIt))
	{
		return false;
	}
	else
	{
		return true;
	}
}


#include <unistd.h>


template <typename T> void PmergeMe::first(T& main, T& rest, T& odd, T& pend)
{
	// check if 2 elements with the size of Group are available in main if yes fill to pend
	int iteration = 2;
	while(true)
	{
		std::cout << BG_BRIGHT_BLACK << "Iteration " << iteration << RESET << std::endl;
		auto StartIt = main.begin();
		auto EndItOfTwoElements = main.begin();
		auto EndIt = main.end();

		// check if b2 is available - set StartIt to b2
		if(validateIterator<T>(main.begin(), main.end(), this->_SizeOfGroup * iteration))
		{
			StartIt = std::next(main.begin(), this->_SizeOfGroup * iteration);
		}
		else
		{
			std::cout << "out of range Start" << std::endl;
			return ;
		}				
		// check if 2 full elements are available from bx
		if(validateIterator<T>(StartIt, main.end(), this->_SizeOfGroup * 2))
		{
			std::cout << "EndItOfTwoElements available" << std::endl;
			EndItOfTwoElements = std::next(StartIt, this->_SizeOfGroup * 2);
			EndIt = std::next(StartIt, this->_SizeOfGroup);
			std::cout << "StartIt " << &(*StartIt) << " " << (*StartIt) << std::endl;
			std::cout << "ENDIT " << &(*EndIt) << " " << (*EndIt) << std::endl;
			std::cout << "EndItOfTwoElements " << &(*EndItOfTwoElements) << " " << (*EndItOfTwoElements) << std::endl;
			pend.insert(pend.end(), StartIt, EndIt );
			main.erase(StartIt, EndIt);				
			printFillContainers(pend , odd,  rest,main);
			std::advance(EndItOfTwoElements, -this->_SizeOfGroup);
		

			// full element is available
			// check size of rest. if rest is bigger than sizeofgroup do nothing.else do below
			std::cout << "EndItOfTwoElements " << &(*EndItOfTwoElements) << " " << (*EndItOfTwoElements) << std::endl;
			size_t remainingElements = static_cast<size_t>(std::distance(EndItOfTwoElements, main.end()));
			std::cout << "remainingElements " << remainingElements << std::endl;
			
			if (remainingElements >= this->_SizeOfGroup && remainingElements < this->_SizeOfGroup * 2)
			{
				if(validateIterator<T>(EndItOfTwoElements, main.end(), this->_SizeOfGroup))
				{
					auto OddEndIt = std::next(EndItOfTwoElements, this->_SizeOfGroup);
					odd.insert(odd.end(), EndItOfTwoElements, OddEndIt);
					main.erase(EndItOfTwoElements, OddEndIt);
				}
				
				std::cout << "TEST" << std::endl;
				std::cout << "EndItOfTwoElements " << &(*EndItOfTwoElements) << " " << (*EndItOfTwoElements) << std::endl;
				printFillContainers(pend , odd,  rest,main);
				// sleep(1);
				
				// rest is available
				remainingElements = static_cast<size_t>(std::distance(EndItOfTwoElements, main.end()));
				std::cout << "remainingElementsForOdd " << remainingElements << std::endl;
				if(EndItOfTwoElements != main.end() && remainingElements < this->_SizeOfGroup)
				{
					rest.insert(rest.end(), EndItOfTwoElements, main.end());
					main.erase(EndItOfTwoElements, main.end());
				}
			}
		}
		else
		{
			std::cout << "out of range EndItOfTwoElements" << std::endl;
			size_t remainingElements = static_cast<size_t>(std::distance(StartIt, main.end()));
			std::cout << BG_BRIGHT_CYAN << "remainingElements " << remainingElements << RESET << std::endl;

			// check if StartIt to EndIt fits to odd elements - odd elements are a full standalone element
			std::cout << BG_BRIGHT_CYAN << "StartIt " << &(*StartIt) << " " << (*StartIt) << RESET << std::endl;
			std::cout << BG_BRIGHT_CYAN  << "main.end() " << &(*main.end()) << " " << (*main.end()) << RESET << std::endl;
			// if(validateIterator<T>(StartIt, main.end(), this->_SizeOfGroup))
			if(remainingElements == this->_SizeOfGroup)
			{
				std::cout << "Insert to odd" << std::endl;
				EndIt = std::next(StartIt, this->_SizeOfGroup);
				std::cout << "ENDIT " << &(*EndIt) << " " << (*EndIt) << std::endl;
				odd.insert(odd.end(), StartIt, EndIt);
				main.erase(StartIt, EndIt);
			}
			else //no full element available so put numbers to rest
			{
				std::cout << "Insert to rest" << std::endl;
				std::cout << "StartIt " << &(*StartIt) << " " << (*StartIt) << std::endl;
				std::cout << "ENDIT " << &(*EndIt) << " " << (*EndIt) << std::endl;
				rest.insert(rest.end(), StartIt, EndIt);
				main.erase(StartIt, EndIt);
			}
		}
		
		printFillContainers(pend , odd,  rest,main);
		iteration += 1;
	}
	return ;
}



template <typename T> void PmergeMe::retrySorting(T& original)
{
	std::cout << BG_BRIGHT_GREEN << "RETRYSORTING" << RESET << std::endl;
	T pend;
	T odd;
	T rest;
	T main = original;
	
	std::cout << BG_BRIGHT_YELLOW << "_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;
	printFillContainers(pend , odd,  rest,main);
	
	first(main, rest, odd, pend);
	
	
	printFillContainers(pend , odd,  rest,main);
	std::cout << BG_BRIGHT_RED << "Start TO FILL " << RESET << std::endl;
	std::cout << BG_BRIGHT_RED << "this->_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;
	{
		std::cout << "-------- Start PEND --------" << std::endl;
		// fill PEND elements to proper place
		auto MainStartIt = main.begin();
		auto MainEndIt = std::next(MainStartIt, this->_SizeOfGroup);
		auto MainElementToCheck = std::prev(MainEndIt);
		int flag = 0;
		while(true)
		{
			if(pend.size())
			{
				auto PendStartIt = pend.begin();
				auto PendEndIt = std::next(PendStartIt, this->_SizeOfGroup);
				auto PendElementToCheck = std::prev(PendEndIt);
				
				// std::cout << "PendStartIt			" << &(*PendStartIt) << " " << (*PendStartIt) << std::endl;
				// std::cout << "PendEndIt			" << &(*PendEndIt) << " " << (*PendEndIt) << std::endl;
				// std::cout << "PendElementToCheck	" << &(*PendElementToCheck) << " " << BG_BRIGHT_BLUE << (*PendElementToCheck) << RESET << std::endl;
				// std::cout << "MainStartIt		" << &(*MainStartIt) << " " << BG_BRIGHT_BLUE << (*MainStartIt) << RESET << std::endl;
				// std::cout << "MainElementToCheck		" << &(*MainElementToCheck) << " " << BG_BRIGHT_BLUE << (*MainElementToCheck) << RESET << std::endl;
				
				
				this->_compareCounter++;
				std::cout << BG_BRIGHT_BLUE << "MainElementToCheck > PendElementToCheck " << (*MainElementToCheck) << " > " << (*PendElementToCheck) << RESET << std::endl;
				if(*MainElementToCheck > *PendElementToCheck)
				{
					main.insert(MainStartIt, PendStartIt, PendEndIt);
					pend.erase(PendStartIt, PendEndIt);
					printFillContainers(pend , odd, rest, main);
					flag = 1;
				}
				
			}
			if(pend.size() <= 0)
			{
				break;
			}
			if(flag)
			{
				MainStartIt = main.begin();
				flag = 0;
			}
			else
			{
				std::advance(MainStartIt, this->_SizeOfGroup);
			}
			// check out of range!?!?!?!?
			MainEndIt = std::next(MainStartIt, this->_SizeOfGroup);
			MainElementToCheck = std::prev(MainEndIt);
			// sleep(2);
		}
	}
	printFillContainers(pend , odd, rest, main);
	{
		std::cout << "-------- Start ODD --------" << std::endl;
		// fill Odd elements to proper place
		auto MainStartIt = main.begin();
		auto MainEndIt = std::next(MainStartIt, this->_SizeOfGroup);
		auto MainElementToCheck = std::prev(MainEndIt);
		while(true)
		{
			// sleep(2);
			if(odd.size())
			{
				auto OddStartIt = odd.begin();
				auto OddEndIt = std::next(OddStartIt, this->_SizeOfGroup);
				auto OddElementToCheck = std::prev(OddEndIt);
				
				std::cout << "StartIt " << &(*OddStartIt) << " " << (*OddStartIt) << std::endl;
				std::cout << "EndIt " << &(*OddEndIt) << " " << (*OddEndIt) << std::endl;
				std::cout << "OddElementToCheck " << &(*OddElementToCheck) << " " << (*OddElementToCheck) << std::endl;
				
				// First Iteration begin of main has to be checked
				this->_compareCounter++;
				std::cout << BG_BRIGHT_GREEN << "MainElementToCheck > OddElementToCheck " << (*MainElementToCheck) << " > " << (*OddElementToCheck) << RESET << std::endl;
				if(*MainElementToCheck > *OddElementToCheck)
				{
					main.insert(MainStartIt, OddStartIt, OddEndIt);
					odd.erase(OddStartIt, OddEndIt);
				}
			}
			if(odd.size() <= 0)
			break;
			// check out of range!?!?!?!?
			std::advance(MainStartIt, this->_SizeOfGroup);
			MainEndIt = std::next(MainStartIt, this->_SizeOfGroup);
			MainElementToCheck = std::prev(MainEndIt);
		}
	}
	printFillContainers(pend , odd, rest, main);
	{
		std::cout << "-------- Start REST --------" << std::endl;
		// fill REST elements to proper place
		main.insert(main.end(), rest.begin(), rest.end());
		rest.erase(rest.begin(), rest.end());

	}
	printFillContainers(pend , odd, rest, main);

	original = main;
	std::cout << BG_BRIGHT_GREEN << "RETRYSORTING END" << RESET << std::endl;
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
			std::cout << BG_BRIGHT_YELLOW << "PEND " << "Start " << *PendStart << " Last " << *PendLastNbr << " End " << *PendEnd << RESET << std::endl;
		} else {
			std::cout << "PEND reached end of container!" << std::endl;
			std::cout << BG_BRIGHT_YELLOW << "PEND " << "Start " << *PendStart << " Last " << *PendLastNbr << " End " << *PendEnd << RESET << std::endl;
		}


		auto MainStart = main.begin();
		while(MainStart != main.end())
		{
			auto MainEnd = std::next(MainStart, this->_SizeOfGroup);
			auto MainLastNbr = std::prev(MainEnd);

			
			this->_compareCounter++;
			std::cout << "PendLastNbr " << *PendLastNbr << " MainLastNbr " << *MainLastNbr << std::endl;
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
	
	T main;
	
	auto iter = original.begin();
	for (size_t i = 0; i < nbrsInEachGroup / 2; i++)
	{
			iter = fillMainBlockWise(iter, main, original, amountOfGroups);
	}
		
		

	// main.insert(main.end(),original.begin(),original.size());

	// main.assign(original.begin(),original.end());


	// if(std::prev(original.end()) != std::prev(main.end()))
		extraordinarySorting(main, original);

	std::copy(main.begin(), main.end(), original.begin());
}


template <typename T> void PmergeMe::pairing(T& original, size_t amountOfGroups)
{
	size_t nbrsInEachGroup = original.size() / amountOfGroups;
	if(nbrsInEachGroup < 2)
		return;
	
	this->_SizeOfGroup = this->_SizeOfGroup * 2;
	this->_levelOfRecursion++;
	// std::cout << YELLOW << "_levelOfRecursion " << _levelOfRecursion << RESET << std::endl;
	std::cout << "amountOfGroups " << amountOfGroups << CYAN << " - nbrsInEachGroup " << nbrsInEachGroup << RESET << std::endl;


	// Get start and end Iterator of each Group depending on the size of the Group
	auto startIt = original.begin();
	auto endIt = std::next(startIt, amountOfGroups * nbrsInEachGroup);
	if (nbrsInEachGroup % 2 == 1)
	{
		endIt = std::next(startIt, amountOfGroups * (nbrsInEachGroup - 1));
	}


	std::cout << YELLOW << "-----------------------------------------" << RESET << std::endl;

	std::cout << CYAN << "this->_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;
	sortToPairs<T>(startIt, endIt, amountOfGroups, nbrsInEachGroup);

	std::cout << BG_MAGENTA << "O R I G I N A L Container" << RESET << std::endl;
	printContainer(original, 0);

	pairing(original, amountOfGroups * 2);


	std::cout << GREEN << "------------------------ PAIRING DONE ------------------------" << RESET << std::endl;
	// std::cout << MAGENTA << "original container" << RESET << std::endl;
	// printContainer<T>(original, amountOfGroups);


	std::cout << YELLOW << "Start sortWithInsertion " << "_levelOfRecursion " << _levelOfRecursion << RESET << std::endl;
	// sortWithInsertion(original, nbrsInEachGroup, amountOfGroups);
	retrySorting(original);
	this->_levelOfRecursion--;
	this->_SizeOfGroup = this->_SizeOfGroup / 2;
	
	std::cout << BG_RED << "this->_levelOfRecursion " << this->_levelOfRecursion << RESET << std::endl;
	std::cout << BG_RED << "this->_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;
	if(this->_SizeOfGroup == 1)
	{
		retrySorting(original);
	}
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