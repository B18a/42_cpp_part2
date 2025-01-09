



#include "../include/ScalarConverter.hpp"


/****************************************/
/*		Constructor / Destructor		*/
/****************************************/
ScalarConverter::ScalarConverter(void){}
ScalarConverter::~ScalarConverter(void){}
ScalarConverter::ScalarConverter(const ScalarConverter& other){(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;	
}



/****************************************/
/*			Member Functions			*/
/****************************************/

double ScalarConverter::transform_value(const std::string& value_as_string)
{
	if(isNotANumber(value_as_string))
		return 0; // TO DO
	else if(isNegativeInfinite(value_as_string))
		return 0; // TO DO
	else if(isPositiveInfinite(value_as_string))
		return 0; // TO DO
	else if(isChar(value_as_string))
		return ConvertToChar(value_as_string);
	else if(isFloat(value_as_string))
		return ConvertToFloat(value_as_string);
	else if(isDouble(value_as_string))
		return ConvertToDouble(value_as_string);
	else if(isInt(value_as_string))
		return ConvertToInt(value_as_string);
	else
		throw std::invalid_argument("Invalid Input");


}

void ScalarConverter::convert(const std::string& value_as_string)
{
	double value = 0;
	try
	{
		value = transform_value(value_as_string);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return ;
	}
	// TO DO
	printAsChar(value);
	printAsInt(value);
	printAsFloat(value);
	printAsDouble(value);
}





