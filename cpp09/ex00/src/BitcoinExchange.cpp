/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:41:08 by ajehle            #+#    #+#             */
/*   Updated: 2025/02/07 14:46:41 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// container map
#include"../include/BitcoinExchange.hpp"

void validateDate(std::string date)
{
	std::string year = date.substr(0,4);
	std::string month = date.substr(5,2);
	std::string day = date.substr(8,2);	
	if(stoi(day) < 1 || stoi(day) > 31)
		throw std::invalid_argument("Invalid day");
	if(stoi(month) < 1 || stoi(month) > 12)
		throw std::invalid_argument("Invalid month");
	if(stoi(year) < 2009 || stoi(year) > 2025)
		throw std::invalid_argument("Invalid month");
}



bool getRates(const std::string& line, std::map<std::string, double>& m)
{
	std::string date = line.substr(0,10);
	std::string valueStr = line.substr(11);
	try 
	{
		double value = std::stod(valueStr);
		validateDate(date);
		m[date] = value;
	}
	catch (const std::exception& e) 
	{
		std::cout << RED << "Conversion error: " << e.what() << " in line: " << line << RESET << std::endl;
		return false;
	}
	return true; 
}


bool	getExchangeRates(std::map<std::string, double>& m)
{
	const std::string filename = "data.csv";
	std::ifstream	input(filename);
	std::string		line;
	bool			isFirstLine = true;
	
	if (!input.is_open())
	{
		std::cout << RED << "Failed to open file : " << filename << RESET << std::endl;
		return 1;
	}
	while (std::getline(input, line)) 
	{
		if (!isFirstLine) 
			getRates(line, m);
		isFirstLine = false;
	}
	return 0;
}