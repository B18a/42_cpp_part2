/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterHelper.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:58 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/23 12:32:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Color.hpp"
#include "../include/ScalarConverterHelper.hpp"
#include "../include/ScalarConverterChar.hpp"
#include "../include/ScalarConverterFloat.hpp"
#include "../include/ScalarConverterDouble.hpp"
#include "../include/ScalarConverterInt.hpp"

#include<cmath>

double transform_value(const std::string& value_as_string)
{
	if(isNotANumber(value_as_string))
		return std::numeric_limits<double>::quiet_NaN();
	else if(isNegativeInfinite(value_as_string))
		return -std::numeric_limits<double>::infinity();
	else if(isPositiveInfinite(value_as_string))
		return std::numeric_limits<double>::infinity();
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



/****************************************/
/*			Compare Functions			*/
/****************************************/
/****************************************/
/*			 isInfinite			*/
/****************************************/
bool isNegativeInfinite(const std::string& value)
{
	if(value == "-inff" || value == "-inf")
		return true;
	return false;
}

bool isPositiveInfinite(const std::string& value)
{
	if(value == "+inff" || value == "+inf")
		return true;
	return false;
}

bool isInfinite(const double& value)
{
	if(std::isinf(value))
		return true;
	return false;
}

/****************************************/
/*			 isNotANumber				*/
/****************************************/
bool isNotANumber(const std::string& value)
{
	if(value == "nanf" || value == "nan")
		return true;
	return false;
}

bool isNotANumber(const double& value)
{
	if(std::isnan(value))
		return true;
	return false;
}


/****************************************/
/*			 printErrorMessage			*/
/****************************************/

void printErrorMessage(const std::string message)
{
	std::cout << RED << message << std::endl;
}

/****************************************/
/*			 printLiteralName			*/
/****************************************/

void printLiteralName(const std::string name)
{
	std::cout << GREEN << name << ":	" << RESET;
}
