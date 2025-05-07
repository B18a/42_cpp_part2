/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:21:41 by ajehle            #+#    #+#             */
/*   Updated: 2025/02/07 14:18:07 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../include/BitcoinExchange.hpp"


void	convertCoins(std::string keyToFind, double value ,std::map<std::string, double>  exchangeRates)
{
	auto it = exchangeRates.lower_bound(keyToFind);
	if (it != exchangeRates.end() && it->first == keyToFind)
	{
        std::cout << "Key: " << it->first << ", Value: " << it->second << "	" << value << "	" << it->second * value << std::endl;
    }
	else
	{ 
        if (it != exchangeRates.begin()) 
		{
            --it;
            std::cout << "Lower Date: " << it->first << ", Value: " << it->second << "	" << value << "	" << it->second * value << std::endl;
        }
		else 
		{
            std::cout << "No Lower Penises are available. lol" << std::endl;
        }
    }
}



void validateValue(std::string line, std::map<std::string, double> exchangeRates)
{
	if(line.size() < 12)
	{
		std::cout << RED << "Invalid line (too short): " << line << RESET << std::endl;
		return; 
	}
	if (line[4] != '-' || line[7] != '-' || (line[10] != ',' && line[10] != '|')) 
	{
		std::cout << RED << "Invalid format: " << line << RESET << std::endl;
		return; 
	}
	std::string date = line.substr(0,10);
	std::string valueStr = line.substr(11);
	double value;
	try 
	{
		value = std::stod(valueStr);
		validateDate(date);
		if(value < 0 || value > 1000)
			throw std::invalid_argument("Invalid value");	
		// std::cout << date << " " << value << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cout << RED << "Conversion error: " << e.what() << " in line: " << line << RESET << std::endl;
		return;
	}
	convertCoins(date, value, exchangeRates);
	return ; 
}

void calcValue(std::string filename, std::map<std::string, double> exchangeRates)
{
	std::ifstream	input(filename);
	std::string		line;
	bool			isFirstLine = true;
	
	if (!input.is_open())
	{
		std::cout << RED << "Failed to open file : " << filename << RESET << std::endl;
		return;
	}
	while (std::getline(input, line)) 
	{
		if (!isFirstLine) 
			validateValue(line, exchangeRates);
		isFirstLine = false;
	}
	return;	
}

int main(int argc, char** argv)
{
	std::map<std::string, double> exchangeRates;
	(void)argv;
	if(argc != 2)
	{
		std::cout << "Missing arguments" << std::endl;
		return 1;
	}
	if(getExchangeRates(exchangeRates))
		return 1;
	calcValue(argv[1], exchangeRates);




	/************/
	/*	DEBUG	*/
	/************/
	// std::cout << GREEN << "\nExtracted Data:\n" << RESET;
	// std::cout << std::fixed << std::setprecision(2);
	// for (auto it = exchangeRates.begin(); it != exchangeRates.end(); ++it) {
	// 	std::cout << it->first << " -> " << it->second << '\n';
	// }

	return 0;
}
