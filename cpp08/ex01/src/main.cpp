/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:21:41 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/31 12:27:42 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../include/Span.hpp"
#include <array>
#include <stdexcept>
#include <iostream>




int main(void)
{
/****************************************/
/*				Basic Test				*/
/****************************************/
std::cout << "Basic Test " << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(1);
		std::cout << "Shortest Span " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
/****************************************/
/*			Exception Test				*/
/****************************************/
std::cout << "\nException Test " << std::endl;
	try
	{
		Span sp(2);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);

		std::cout << "Shortest Span " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



/****************************************/
/*			Big Span Test				*/
/****************************************/
std::cout << "\nBig Span Test " << std::endl;
	try
	{
		Span bigSpan(10000);
		std::vector<int> largeNumbers;
		for (int i = 0; i < 10000; ++i)
			largeNumbers.push_back(i);
		
		bigSpan.addManyNumbers(largeNumbers.begin(), largeNumbers.end());
		
		std::cout << bigSpan.shortestSpan() << std::endl;
		std::cout << bigSpan.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}