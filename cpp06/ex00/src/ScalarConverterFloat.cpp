



#include "../include/ScalarConverter.hpp"

/****************************************/
/*			Compare Functions			*/
/****************************************/

bool ScalarConverter::isFloat(const std::string& value)
{
	if(value.find('f') != std::string::npos)
		return true;
	return false;
}

/****************************************/
/*			Converter Functions			*/
/****************************************/

double ScalarConverter::ConvertToFloat(const std::string& value)
{
	return (std::stof(value));
}

/****************************************/
/*			Print Functions				*/
/****************************************/

void ScalarConverter::printAsFloat(const double& value)
{
	std::cout 	<< GREEN
				<< "float: "
				<< RESET;		
	if(isNotANumber(value))
		printErrorMessage("nanf");
	else if(isInfinite(value))
		if(value < 0)
			printErrorMessage("-inff");
		else
			printErrorMessage("+inff");
	else 
		std::cout 	<< std::fixed << std::setprecision( 1 )
					<< static_cast<float>(value) 
					<< "f" 
					<< std::endl;	
}
