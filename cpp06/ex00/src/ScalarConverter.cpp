/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:15 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/23 12:32:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/ScalarConverterHelper.hpp"
#include "../include/ScalarConverterChar.hpp"
#include "../include/ScalarConverterFloat.hpp"
#include "../include/ScalarConverterDouble.hpp"
#include "../include/ScalarConverterInt.hpp"

/****************************************/
/*		Constructor / Destructor		*/
/****************************************/

ScalarConverter::ScalarConverter(void){}
ScalarConverter::~ScalarConverter(void){}
ScalarConverter::ScalarConverter(const ScalarConverter& other){(void)other;}

/****************************************/
/*		Copy Assignment Operator		*/
/****************************************/
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;	
}

/****************************************/
/*			Member Functions			*/
/****************************************/

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
		printLiteralName("char");
		printErrorMessage("impossible");
		printLiteralName("int");
		printErrorMessage("impossible");
		printLiteralName("float");
		printErrorMessage("impossible");
		printLiteralName("double");
		printErrorMessage("impossible");
		return ;
	}
	printAsChar(value);
	printAsInt(value);
	printAsFloat(value);
	printAsDouble(value);
}
