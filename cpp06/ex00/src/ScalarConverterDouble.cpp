



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
		printErrorMessage("nan");
	else if(isInfinite(value))
		if(value < 0)
			printErrorMessage("-inf");
		else
			printErrorMessage("+inf");
	else 
		std::cout 	<< std::fixed << std::setprecision( 1 )
					<< static_cast<double>(value) 
					<< std::endl;	
}

