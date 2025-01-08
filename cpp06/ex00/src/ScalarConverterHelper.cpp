



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

bool ScalarConverter::isDouble(const std::string& value)
{
	if(value.find('f') != std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& value)
{
	int i = 0;
    if (value[0] == '+' || value[0] == '-') 
		i++;
    while(i < value.length())
	{
        if (!std::isdigit(value[i]))
			return false;
		i++;
    }
	return true;
}


bool ScalarConverter::isNegativeInfinite(const std::string& value)
{
	if(value == "-inff" || value == "-inf")
		return true;
	return false;
}

bool ScalarConverter::isPositiveInfinite(const std::string& value)
{
	if(value == "+inff" || value == "+inf")
		return true;
	return false;
}

bool ScalarConverter::isUndefined(const std::string& value)
{
	if(value == "nanf" || value == "nan")
		return true;
	return false;
}

/****************************************/
/*			Converter Functions			*/
/****************************************/

float ScalarConverter::ConvertToFloat(const std::string& value)
{
	return (std::stof(value));
}

float ScalarConverter::ConvertToDouble(const std::string& value)
{
	return (std::stod(value));
}

float ScalarConverter::ConvertToInt(const std::string& value)
{
	return (std::stoi(value));
}

/****************************************/
/*			Print Functions				*/
/****************************************/

void ScalarConverter::printAsFloat(const float& value)
{
	
}
