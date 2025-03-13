




#include"../include/PmergeMe.hpp"

void 	PmergeMe::run(int argc, char** argv)
{
	if(parseInput(argc, argv))
		throw WrongInputException();
	fillContainer(argc, argv);

	sorting(this->_vector);
	sorting(this->_deque);

	if(std::is_sorted(this->_vector.begin(), this->_vector.end()))
	{
		std::cout << "sorted vector" << std::endl;
	}
	if(std::is_sorted(this->_deque.begin(), this->_deque.end()))
	{
		std::cout << "sorted deque" << std::endl;
	}

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
		if(atol(argv[i]) > INT_MAX)
		{
			throw WrongOutofRangeException();
		}
		_vector.push_back(atoi(argv[i]));
		_deque.push_back(atoi(argv[i]));
		i++;
	}
	// printContainer(_vector, 0);
	// printContainer(_deque, 0);
}


template <typename T> void PmergeMe::sorting(T& original)
{
	// T main;
	this->_compareCounter = 0;
	this->_levelOfRecursion = 0;
	this->_jakobNumber = 3;
	this->_jakobNumberOld = 1;
	this->_jakobNumberIdx = 3;
	this->_SizeOfGroup = 1;
	this->_bCounter = 0;
	auto start = std::chrono::high_resolution_clock::now();
	pairing(original, 1);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time to execute : " << duration.count() << " microseconds" << std::endl;
	std::cout << "Compares : " << this->_compareCounter << std::endl;

	std::cout << CYAN << "Main Container" << RESET << std::endl;
	printContainer<T>(original, 0);
	std::cout << BG_CYAN << "_compareCounter " << this->_compareCounter << RESET << std::endl;

}


// for first iteration we have 1 Group so we have to check groups of 2 nbrs (first if condition)
// all other iterations the nbrs in each group get mulitplied by 2: 2,4,8,16, and so on

template <typename T> 
void	PmergeMe::sortToPairs(typename T::iterator startIt, typename T::iterator endIt, size_t amountOfGroups)
{
	auto newIt = startIt;
	while (newIt != endIt)
	{
		// std::cout << CYAN << "ELEMENT OF TWO" << RESET << std::endl;
		if(this->_SizeOfGroup == 2)
		{
			auto BlockOneStartIt = newIt;
			auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfGroups);
			_compareCounter++;
			if(*BlockOneStartIt > *BlockOneEndIt)
			{
				std::iter_swap(BlockOneStartIt, BlockOneEndIt);
			}
		}
		// std::cout << CYAN << "ELEMENT OF MULTIPLE" << RESET << std::endl;
		else
		{
			auto BlockOneStartIt = newIt;
			auto BlockOneEndIt = std::next(BlockOneStartIt, amountOfGroups - 1);
			auto BlockTwoStartIt = std::next(BlockOneStartIt, amountOfGroups);
			auto BlockTwoEndIt = std::next(BlockTwoStartIt, amountOfGroups - 1);

			if (BlockTwoStartIt >= endIt || BlockTwoEndIt > endIt)
			{
				this->_SizeOfGroup = this->_SizeOfGroup / 2;
				break;
			}
			_compareCounter++;
			if(*BlockOneEndIt > *BlockTwoEndIt)
			{
				std::swap_ranges(BlockOneStartIt, BlockTwoStartIt, BlockTwoStartIt);
			}
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

	// std::cout << MAGENTA << "main container" << RESET << std::endl;
	// printContainer(main, 0);
	// std::cout << MAGENTA << "original container" << RESET << std::endl;
	printContainer(original, 0);


	std::cout << BG_MAGENTA << "fillMainBlockWise END" << RESET << std::endl;
	return BlockTwoEndIt;
	
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


template <typename T> void PmergeMe::prepareContainer(T& main, T& rest, T& odd, T& pend)
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
			std::cout << "B2------------------------------------START" << std::endl;
		}
		else
		{
			std::cout << "out of range Start" << std::endl;
			return ;
		}	
			
		// check if 2 full elements are available from bx
		if(validateIterator<T>(StartIt, EndIt, this->_SizeOfGroup * 2) || this->_SizeOfGroup == 1)
		{
			// std::cout << "EndItOfTwoElements available" << std::endl;
			EndItOfTwoElements = std::next(StartIt, this->_SizeOfGroup * 2);
			EndIt = std::next(StartIt, this->_SizeOfGroup);
			pend.insert(pend.end(), StartIt, EndIt );			
			
			auto offset = std::distance(main.begin(), EndItOfTwoElements);  // Store position before erase
			main.erase(StartIt, EndIt);  // This might invalidate all iterators in std::deque
			EndItOfTwoElements = std::next(main.begin(), offset);  // Restore iterator using offset
			std::advance(EndItOfTwoElements, -this->_SizeOfGroup);

			// full element is available
			// check size of rest. if rest is bigger than sizeofgroup do nothing.else do below
			size_t remainingElements = static_cast<size_t>(std::distance(EndItOfTwoElements, main.end()));			
			if (remainingElements >= this->_SizeOfGroup && remainingElements < this->_SizeOfGroup * 2)
			{
				if(validateIterator<T>(EndItOfTwoElements, main.end(), this->_SizeOfGroup))
				{
					auto OddEndIt = std::next(EndItOfTwoElements, this->_SizeOfGroup);
					odd.insert(odd.end(), EndItOfTwoElements, OddEndIt);
					main.erase(EndItOfTwoElements, OddEndIt);
				}
				
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
			size_t remainingElements = static_cast<size_t>(std::distance(StartIt, main.end()) / this->_SizeOfGroup);
			std::cout << BG_BRIGHT_CYAN << "remainingElements " << remainingElements << RESET << std::endl;

			// check if StartIt to EndIt fits to odd elements - odd elements are a full standalone element
			std::cout << BG_BRIGHT_CYAN << "StartIt " << &(*StartIt) << " " << (*StartIt) << RESET << std::endl;
			std::cout << BG_BRIGHT_CYAN  << "main.end() " << &(*main.end()) << " " << (*main.end()) << RESET << std::endl;
			if(remainingElements)
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
		// printFillContainers(pend , odd,  rest,main);
		iteration += 1;
	}
	return ;
}



std::vector<int>::iterator custom_lower_bound(std::vector<int>::iterator begin, 
	std::vector<int>::iterator end, 
	int value, int step, int& compareCount) 
{
	auto left = begin;
	auto right = end;

	while (std::distance(left, right) >= step) 
	{ // Ensure meaningful step distance
		auto dist = std::distance(left, right);
		std::cout << BG_BRIGHT_BLACK << "dist " << dist << " elements " << dist/step << " left " << *left << " right " << *right << RESET << std::endl;
		
		// auto mid = left + (dist / (2 * step)) * step + 1; // Select step-aligned midpoint
		auto mid = left;
		if(dist/step != 1)
		{
			mid = std::next(left, dist/step * step);
		}
		
		if (mid >= right) // Prevent overshooting
		{
			mid = right - step;
		}
		
		++compareCount;
		std::cout << "*mid < value: " << *mid << " vs " << value << std::endl;

		if (*mid < value)
			left = mid + step; // Move right by step
		else
			right = mid; // Move left
	}

	std::cout << "Total Comparisons: " << compareCount << std::endl;
	std::cout << "left: " << *left << std::endl;
	left++;
	return left; // First position where !(value > *it)
}


std::deque<int>::iterator lowerB(std::deque<int>& SearchContainer, int value, int& compareCount) 
{
	std::cout << "lowerB called\n";
	std::cout << "value: " << value << "\n";

	auto it = std::lower_bound(SearchContainer.begin(), SearchContainer.end(), value, [&](const int& a, const int& b)
	{ 
		// std::cout << "a " << a << " b " << b << std::endl;
			++compareCount;
			return a < b; 
	});

	if (it != SearchContainer.end()) {
		std::cout << "Iterator points to: " << *it << "\n";
	} else {
		std::cout << "Iterator at end()\n";
	}

	std::cout << "Total comparisons: " << compareCount << "\n";
	std::cout << "lowerB END\n";
	return it;
}


void	PmergeMe::fillPendToMain_StartIndexUpdate(int& StartIndex, int& insertCount)
{
	std::cout << BG_BRIGHT_GREEN << "StartIndexUPDATE	" << RESET << std::endl;
	this->_jakobNumberOld = this->_jakobNumber;
	this->_jakobNumberIdx++;
	this->_jakobNumber = jakobsthal_recursive(this->_jakobNumberIdx);
	StartIndex = this->_jakobNumber - this->_jakobNumberOld - 1;
	this->_searchRange = this->_jakobNumber + insertCount;
}

template <typename T> void PmergeMe::fillPendToMain(T&main, T&pend)
{
	std::cout << "-------- Start PEND --------" << std::endl;
	this->_jakobNumberOld = 1;
	this->_jakobNumberIdx = 3;
	this->_jakobNumber = 3;
	this->_searchRange = 2;

	int	insertCount = 0;

	auto MainStartIt = std::next(main.begin(), (this->_searchRange / 2) * this->_SizeOfGroup);
	auto MainEndIt = std::next(MainStartIt, this->_SizeOfGroup);
	auto MainElementToCheck = std::prev(MainEndIt);
	int InsertionFlag = 0;
	int StartIndex = this->_jakobNumber - this->_jakobNumberOld - 1;
	while(true)
	{
		if(pend.size())
		{
			auto PendStartIt = pend.begin();

			if(StartIndex < 0)
			{
				fillPendToMain_StartIndexUpdate(StartIndex, insertCount);
			}
			while (StartIndex >= 0) {
				auto offset = StartIndex * this->_SizeOfGroup;
				if (validateIterator<T>(pend.begin(), pend.end(), offset)) {
					PendStartIt = std::next(pend.begin(), offset);
					break;
				}
				StartIndex--;
			}
			// while(StartIndex >= 0)
			// {
			// 	if(validateIterator<T>(pend.begin(),pend.end(), StartIndex * this->_SizeOfGroup))
			// 	{
			// 		if(StartIndex * this->_SizeOfGroup == 0)
			// 		{
			// 			PendStartIt = pend.begin();
			// 		}
			// 		else
			// 		{
			// 			PendStartIt = std::next(pend.begin(), StartIndex * this->_SizeOfGroup);
			// 		}
			// 		break;			
			// 	}
			// 	StartIndex--;
			// }
			auto PendEndIt = std::next(PendStartIt, this->_SizeOfGroup);
			auto PendElementToCheck = std::prev(PendEndIt);

			// update MainElementToCheck
			// Binary insert here
			{


			std::deque<int> SearchContainer;
			{
					std::cout << "SearchContainer " << std::endl;
					std::cout << "this->_searchRange " << this->_searchRange << std::endl;
					auto Iter = std::next(main.begin(), this->_SizeOfGroup - 1);
					SearchContainer.push_back(*Iter);

					int amountOfGroups = main.size()/this->_SizeOfGroup;
					if(amountOfGroups > this->_searchRange)
						amountOfGroups--;
					
					int i = 1;
					while(i < amountOfGroups && Iter != std::prev(main.end()))
					{
						std::advance(Iter, this->_SizeOfGroup);
						i++;
						SearchContainer.push_back(*Iter);
					}

					// printContainer(SearchContainer,1);
					std::cout << "SearchContainer END" << std::endl;
			}
				std::cout << BG_BRIGHT_BLUE << "PendElementToCheck " << (*PendElementToCheck) << RESET << std::endl;

				auto it = lowerB(SearchContainer, *PendElementToCheck, this->_compareCounter);
				if(it == SearchContainer.end())
				{
					std::cout << "END END END" << std::endl;

					auto EndOfGroup = main.begin();
					if(validateIterator<T>(main.begin(), main.end(), this->_SizeOfGroup * this->_searchRange) == false)
					{
						std::cout << "--------->	OFF " << std::endl;
						EndOfGroup = main.end();
					}
					else
					{
						EndOfGroup = std::next(main.begin(), this->_SizeOfGroup * this->_searchRange);
					}
					std::cout << "EndOfGroup " << *EndOfGroup << std::endl;
					main.insert(EndOfGroup, PendStartIt, PendEndIt);

				}
				else
				{
					auto Found = std::find(main.begin(), main.end(), *it);
					auto Insert = std::next(main.begin(), this->_SizeOfGroup - 1);
					
					if(Insert == Found)
					{
						main.insert(main.begin(), PendStartIt, PendEndIt);
					}
					else
					{	
						while(Insert != Found)
						{
							auto test = std::next(Insert, this->_SizeOfGroup);
							if(*test != *Found)
							{
								std::advance(Insert, this->_SizeOfGroup);
							}
							else
							{
								break;
							}
						}
						Insert++;
						std::cout << "Insert place " << *Insert << " it " << *it << std::endl;
						main.insert(Insert, PendStartIt, PendEndIt);
					}
				}
				{
					pend.erase(PendStartIt, PendEndIt);
					InsertionFlag = 1;
					StartIndex--;
					insertCount++;
				}
			}
		}
		if(pend.size() <= 0)
		{
			break;
		}
		if(InsertionFlag)
		{
			InsertionFlag = 0;
			MainStartIt = main.begin();				
		}
		else
		{
			std::advance(MainStartIt, this->_SizeOfGroup);
		}

		// must be set to next half depending on > or < from last element
		MainEndIt = std::next(MainStartIt, this->_SizeOfGroup);
		MainElementToCheck = std::prev(MainEndIt);
	}
std::cout << "-------- End PEND --------" << std::endl;
}

template <typename T>	void PmergeMe::fillOddToMain(T&main, T&odd)
{
	std::cout << "-------- Start ODD --------" << std::endl;
	auto MainStartIt = main.begin();
	auto MainEndIt = std::next(MainStartIt, this->_SizeOfGroup);
	auto MainElementToCheck = std::prev(MainEndIt);
	while(true)
	{
		if(odd.size())
		{
			auto OddStartIt = odd.begin();
			auto OddEndIt = std::next(OddStartIt, this->_SizeOfGroup);
			auto OddElementToCheck = std::prev(OddEndIt);
			this->_compareCounter++;
			if(*MainElementToCheck > *OddElementToCheck)
			{
				main.insert(MainStartIt, OddStartIt, OddEndIt);
				odd.erase(OddStartIt, OddEndIt);
			}
		}
		if(odd.size() <= 0)
		{
			break;
		}
		if(validateIterator<T>(MainStartIt, main.end(), this->_SizeOfGroup) == false)
		{
			std::cout << RED << "END OF CONTAINER REACHED!!!" << RESET << std::endl;
			main.insert(main.end(), odd.begin(), (std::next(odd.begin(), this->_SizeOfGroup)));
			odd.erase(odd.begin(), (std::next(odd.begin(), this->_SizeOfGroup)));
			break;
		}
		std::advance(MainStartIt, this->_SizeOfGroup);
		MainEndIt = std::next(MainStartIt, this->_SizeOfGroup);
		MainElementToCheck = std::prev(MainEndIt);
	}
std::cout << "-------- End ODD --------" << std::endl;

}

template <typename T>	void PmergeMe::fillRestToMain(T&main, T&rest)
{
	std::cout << "-------- Start REST --------" << std::endl;
	main.insert(main.end(), rest.begin(), rest.end());
	rest.erase(rest.begin(), rest.end());
	
	std::cout << "-------- End REST --------" << std::endl;
}

template <typename T> void PmergeMe::retrySorting(T& original)
{
	std::cout << BG_BRIGHT_GREEN << "RETRYSORTING" << RESET << std::endl;
	T pend;
	T pendCpy;
	T odd;
	T rest;
	T main = original;
	
	std::cout << BG_BRIGHT_YELLOW << "_SizeOfGroup " << this->_SizeOfGroup << RESET << std::endl;
	
	prepareContainer(main, rest, odd, pend);

	std::cout << BG_BRIGHT_RED << "Start TO FILL " << RESET << std::endl;
	fillPendToMain(main, pend);
	fillOddToMain(main, odd);
	fillRestToMain(main, rest);
	printFillContainers(pend , odd, rest, main);
	original = main;
	std::cout << BG_BRIGHT_GREEN << "RETRYSORTING END" << RESET << std::endl;
}

template <typename T> void PmergeMe::sortWithInsertion(T& original, size_t nbrsInEachGroup, size_t amountOfGroups)
{
	T main;
	
	auto iter = original.begin();
	for (size_t i = 0; i < nbrsInEachGroup / 2; i++)
	{
			iter = fillMainBlockWise(iter, main, original, amountOfGroups);
	}
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
	auto startIt = original.begin();
	auto endIt = std::next(startIt, amountOfGroups * nbrsInEachGroup);
	if (nbrsInEachGroup % 2 == 1)
	{
		endIt = std::next(startIt, amountOfGroups * (nbrsInEachGroup - 1));
	}
	sortToPairs<T>(startIt, endIt, amountOfGroups);

	pairing(original, amountOfGroups * 2);

	retrySorting(original);
	this->_levelOfRecursion--;
	this->_SizeOfGroup = this->_SizeOfGroup / 2;

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

const char* PmergeMe::WrongOutofRangeException::what() const noexcept
{
	return "PmergeMe Number out of Range";
}





// 2 11 0 16 6 15 8 17 9 18 14 19 3 10 1 21 5 12 4 20 7 13 

// ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
// 22 numbers


// ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 99 18 9 14 19 12 5 4 100