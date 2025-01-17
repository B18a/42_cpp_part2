/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterHelper.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:58 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 09:40:00 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/****************************************/
/*			Compare Functions			*/
/****************************************/
/****************************************/
/*			 isInfinite			*/
/****************************************/
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

bool ScalarConverter::isInfinite(const double& value)
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


/****************************************/
/*			 printErrorMessage			*/
/****************************************/

void ScalarConverter::printErrorMessage(const std::string message)
{
	std::cout << RED << message << std::endl;
}

/****************************************/
/*			 printLiteralName			*/
/****************************************/

void ScalarConverter::printLiteralName(const std::string name)
{
	std::cout << GREEN << name << ":	" << RESET;
}
