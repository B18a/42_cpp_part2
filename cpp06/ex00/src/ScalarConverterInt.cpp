



#include "../include/ScalarConverter.hpp"

/****************************************/
/*			Compare Functions			*/
/****************************************/

static bool isValidInt(const double& value)
{
	 if (std::isfinite(value) && 
           value >= std::numeric_limits<int>::min() && 
           value <= std::numeric_limits<int>::max())
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

/****************************************/
/*			Converter Function			*/
/****************************************/

double ScalarConverter::ConvertToInt(const std::string& value)
{
	return (std::stoi(value));
}

/****************************************/
/*			Print Function					*/
/****************************************/

void ScalarConverter::printAsInt(const double& value)
{
	printLiteralName("int");
	if(std::isnan(value) || !isValidInt(value))
		printErrorMessage("impossible");
	else 
		std::cout 	<< (value) 
					<< std::endl;

}