/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterInt.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:40:05 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/23 14:39:52 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverterHelper.hpp"
#include<cmath>

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

bool isInt(const std::string& value)
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

double ConvertToInt(const std::string& value)
{
	return (std::stoi(value));
}

/****************************************/
/*			Print Function					*/
/****************************************/

void printAsInt(const double& value)
{
	printLiteralName("int");
	if(std::isnan(value) || !isValidInt(value))
		printErrorMessage("impossible");
	else 
		std::cout 	<< static_cast<int>(value) 
					<< std::endl;

}