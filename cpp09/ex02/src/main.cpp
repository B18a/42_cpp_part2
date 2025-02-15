



#include"../include/PmergeMe.hpp"
#include <string>
#include <iostream>



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
#define RESET   "\033[0m" 





int main(int argc, char** argv)
{
	// int arr[] = {5,3,7,9,6,4};
	if(argc <= 1)
		return 1;
	try
	{
		PmergeMe pm;
		pm.run(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;

}

