



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
	if(isFloat(value_as_string))
		return getFloat(value_as_string);
	else if(isDouble(value_as_string))
		return getDouble(value_as_string);
	else if(isInt(value_as_string))
		return getInt(value_as_string);


}

void ScalarConverter::convert(const std::string& value_as_string)
{
	double value = 0;

	value = transform_value(value_as_string);

	printFloat(value);
}





