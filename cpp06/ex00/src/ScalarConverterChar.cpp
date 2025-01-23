/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterChar.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:34 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/23 09:52:00 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverterHelper.hpp"
#include<cmath>

/****************************************/
/*			Compare Functions			*/
/****************************************/

bool isChar(const std::string& value)
{
	if(value.size() == 3 && value[0] == '\'' && isprint(value[1]) && value[2] == '\'')
		return true;
	return false;
}

/****************************************/
/*			Converter Function			*/
/****************************************/

double ConvertToChar(const std::string& value)
{
	return (static_cast<double>(value[1]));
}

/****************************************/
/*			Print Function					*/
/****************************************/

void printAsChar(const double& value)
{
	printLiteralName("char");
	if(std::isnan(value) || value < 0 || value > 127)
		printErrorMessage("impossible");
	else if(!std::isprint(static_cast<int>(value)))
		printErrorMessage("not displayable");
	else 
		std::cout 	<<"'"
					<< static_cast<char>(value) 
					<<"'"
					<< std::endl;	
}

