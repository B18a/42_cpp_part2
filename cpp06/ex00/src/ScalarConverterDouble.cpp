



#include "../include/ScalarConverter.hpp"

/****************************************/
/*			Compare Functions			*/
/****************************************/

bool ScalarConverter::isDouble(const std::string& value)
{
	if(value.find('.') != std::string::npos)
		return true;
	return false;
}

/****************************************/
/*			Converter Functions			*/
/****************************************/

double ScalarConverter::ConvertToDouble(const std::string& value)
{
	return (std::stod(value));
}

/****************************************/
/*			Print Functions				*/
/****************************************/

void ScalarConverter::printAsDouble(const double& value)
{
	std::cout 	<< GREEN
				<< "double: "
				<< RESET;
	if(isNotANumber(value))
		std::cout 	<< RED
					<< "nan"
					<< RESET
					<< std::endl;
	else if(isNegativeInfinite(value))
		std::cout 	<< RED
					<< "-inf"
					<< RESET
					<< std::endl;
	else if(isPositiveInfinite(value))
		std::cout 	<< RED
					<< "+inf"
					<< RESET
					<< std::endl;
	else 
		std::cout 	<< std::fixed << std::setprecision( 1 )
					<< static_cast<double>(value) 
					<< std::endl;	
}

