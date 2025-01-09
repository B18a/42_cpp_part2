



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
/*			Converter Function			*/
/****************************************/

double ScalarConverter::ConvertToFloat(const std::string& value)
{
	return (std::stof(value));
}

/****************************************/
/*			Print Function					*/
/****************************************/

void ScalarConverter::printAsFloat(const double& value)
{
	printLiteralName("float");
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
