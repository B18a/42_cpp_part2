



#include "../include/ScalarConverter.hpp"

/****************************************/
/*			Compare Functions			*/
/****************************************/

bool ScalarConverter::isChar(const std::string& value)
{
	if(value.size() == 3 && value[0] == '\'' && isprint(value[1]) && value[2] == '\'')
		return true;
	return false;
}



/****************************************/
/*			Converter Functions			*/
/****************************************/

double ScalarConverter::ConvertToChar(const std::string& value)
{
	return (static_cast<double>(value[1]));
}



/****************************************/
/*			Print Functions				*/
/****************************************/


void ScalarConverter::printAsChar(const double& value)
{

	std::cout 	<< GREEN
				<< "char: "
				<< RESET;

	if(std::isnan(value) || value < 0 || value > 32)
		std::cout 	<< RED
					<< "impossible"
					<< RESET
					<< std::endl;
	else if(!std::isprint(static_cast<int>(value)))
		std::cout 	<< RED
					<< "not displayable"
					<< RESET
					<< std::endl;
	else 
		std::cout 	<< static_cast<char>(value) 
					<< std::endl;	


}

