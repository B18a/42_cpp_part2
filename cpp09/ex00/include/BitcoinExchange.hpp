/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:41:10 by ajehle            #+#    #+#             */
/*   Updated: 2025/02/07 15:23:49 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


HEADERPROTECTION!!!!!!!

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <unistd.h>

#include <map>

/****************************************/
/*			Text Colors 				*/
/****************************************/

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m" 



void validateDate(std::string date);
bool getRates(const std::string& line, std::map<std::string, double>& m);
bool	getExchangeRates(std::map<std::string, double>& m);


