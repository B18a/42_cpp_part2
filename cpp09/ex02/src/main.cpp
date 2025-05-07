



#include"../include/PmergeMe.hpp"
#include <string>
#include <iostream>








int main(int argc, char** argv)
{
	// int arr[] = {5,3,7,9,6,4};
	if(argc <= 1)
		return 1;
	try
	{
		PmergeMe pm;
		std::cout << GREEN << "-------- START --------" << RESET << std::endl;
		pm.run(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;

}

// 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

// Duplicate Handling!!!!!!!!!!!!!!!!!!!!!!!!