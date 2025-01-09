



#include "../include/ScalarConverter.hpp"

/****************************************/
/*			Compare Functions			*/
/****************************************/
/****************************************/
/*			 isNegativeInfinite			*/
/****************************************/
bool ScalarConverter::isNegativeInfinite(const std::string& value)
{
	if(value == "-inff" || value == "-inf")
		return true;
	return false;
}

bool ScalarConverter::isNegativeInfinite(const double& value)
{
	if(std::isinf(value))
		return true;
	return false;
}

/****************************************/
/*			 isPositiveInfinite			*/
/****************************************/
bool ScalarConverter::isPositiveInfinite(const std::string& value)
{
	if(value == "+inff" || value == "+inf")
		return true;
	return false;
}

bool ScalarConverter::isPositiveInfinite(const double& value)
{
	if(std::isinf(value))
		return true;
	return false;
}

/****************************************/
/*			 isNotANumber				*/
/****************************************/
bool ScalarConverter::isNotANumber(const std::string& value)
{
	if(value == "nanf" || value == "nan")
		return true;
	return false;
}

bool ScalarConverter::isNotANumber(const double& value)
{
	if(std::isnan(value))
		return true;
	return false;
}
