



#include "../include/ScalarConverter.hpp"

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

float ScalarConverter::getInt(const std::string& value)
{
	return (std::stoi(value));
}


bool ScalarConverter::isFloat(const std::string& value)
{
	if(value.find('f') != std::string::npos)
		return true;
	return false;
}

float ScalarConverter::getFloat(const std::string& value)
{
	return (std::stof(value));
}


bool ScalarConverter::isDouble(const std::string& value)
{
	if(value.find('f') != std::string::npos)
		return true;
	return false;
}

float ScalarConverter::getDouble(const std::string& value)
{
	return (std::stod(value));
}




bool ScalarConverter::isInfinite(const std::string& value)
{
	if(value == "-inff" || value == "-inf" || value == "+inff" || value == "+inf")
		return true;
	return false;
}


bool ScalarConverter::isUndefined(const std::string& value)
{
	if(value == "nanf" || value == "nan")
		return true;
	return false;
}




void ScalarConverter::printFloat(const float& value)
{
	
}
