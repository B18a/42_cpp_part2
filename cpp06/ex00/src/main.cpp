#include"../include/ScalarConverter.hpp"


int main(int argc, char** argv)
{

	(void)argc;
	// std::cout << argv[1] << std::endl;
	if(argc == 2)
		ScalarConverter::convert(argv[1]);
	return 0;
}



// 1. get (Literal)Type
// 2. convert string to Literal Type
// 3. print string in all Literal Types
// 		- char
// 		- int
// 		- float
// 		- double
