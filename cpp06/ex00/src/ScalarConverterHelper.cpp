



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
	size_t i = 0;
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

/****************************************/
/*			Converter Functions			*/
/****************************************/

double ScalarConverter::ConvertToChar(const std::string& value)
{
	return (static_cast<double>(value[1]));
}

double ScalarConverter::ConvertToFloat(const std::string& value)
{
	return (std::stof(value));
}

double ScalarConverter::ConvertToDouble(const std::string& value)
{
	return (std::stod(value));
}

double ScalarConverter::ConvertToInt(const std::string& value)
{
	return (std::stoi(value));
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
		std::cout << value;
	else 
		std::cout 	<< std::fixed 
					<< std::setprecision( 1 )
					<< static_cast<float>(value) 
					<< "f" 
					<< std::endl;
			
	
}
