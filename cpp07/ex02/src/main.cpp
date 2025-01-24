#include <iostream>
#include"../include/Array.hpp"


int main(void)
{

/****************************************/
/*					INT					*/
/****************************************/
std::cout << "Array of INT" << std::endl;
	try
	{
		Array<int> numbers(5);
		for(int i = 0; i < 5; i++)
			numbers[i] = i;
		for(int i = 0; i < 5; i++)
			std::cout << numbers[i] << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

/****************************************/
/*				STRING					*/
/****************************************/
std::cout << "Array of Strings" << std::endl;

	try
	{
		Array<std::string> string(2);
		string[0] = "banane";
		string[1] = "peach";
		for(int i = 0; i < 2; i++)
			std::cout << string[i] << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


/****************************************/
/*				Exception				*/
/****************************************/
std::cout << "Exception" << std::endl;

	try
	{
		Array<std::string> string(0);
		std::cout << string[5] << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}