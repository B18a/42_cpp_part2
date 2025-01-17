/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterDouble.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:41 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 09:39:43 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/****************************************/
/*			Compare Functions			*/
/****************************************/

bool ScalarConverter::isDouble(const std::string& value)
{
	if(value.find('.') != std::string::npos)
		return true;
	return false;
}

/****************************************/
/*			Converter Function			*/
/****************************************/

double ScalarConverter::ConvertToDouble(const std::string& value)
{
	return (std::stod(value));
}

/****************************************/
/*			Print Function					*/
/****************************************/

void ScalarConverter::printAsDouble(const double& value)
{
	printLiteralName("double");
	if(isNotANumber(value))
		printErrorMessage("nan");
	else if(isInfinite(value))
		if(value < 0)
			printErrorMessage("-inf");
		else
			printErrorMessage("+inf");
	else 
		std::cout 	<< std::fixed << std::setprecision( 1 )
					<< static_cast<double>(value) 
					<< std::endl;	
}

