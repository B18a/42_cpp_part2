/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:21:41 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/30 16:40:05 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../include/easyfind.hpp"
#include <array>
#include <list>
#include <vector>
#include <stdexcept>
#include <iostream>

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


template <typename T>
void print_container(const T& container)
{
	std::cout << "Printing Values and Addresses" << std::endl;
	typename T::const_iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << "Value " << GREEN << *it << RESET <<  " at Address " << CYAN << &(*it) << RESET << std::endl;
		it++;
	}
	std::cout << std::endl;
}


int main(void)
{
	/****************************************/
	/*			Container Array 			*/
	/****************************************/
	std::cout << "Testing with " << BLUE << "ARRAY" << RESET << " of int" << std::endl;
	std::array<int, 3> arraylist = {3,2,1};
	try
	{
		print_container(arraylist);
		// std::array<int, 3>::const_iterator result = easyfind(arraylist, 3);
		auto result = easyfind(arraylist, 3);
		std::cout << "Searching Value" << std::endl;
		std::cout << "Value " << GREEN << *result << RESET <<  " at Address " << CYAN << &(*result) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	/****************************************/
	/*			Container List	 			*/
	/****************************************/
	std::cout << "\n\nTesting with " << BLUE << "LIST" << RESET << " of int" << std::endl;
	std::list<int> listlist;
	listlist.push_back(3);
	listlist.push_back(2);
	listlist.push_back(5);
	try
	{
		
		print_container(listlist);
		// std::list<int>::const_iterator result = easyfind(listlist, 5);
		auto result = easyfind(listlist, 5);
		std::cout << "Searching Value" << std::endl;
		std::cout << "Value " << GREEN << *result << RESET <<  " at Address " << CYAN << &(*result) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	/****************************************/
	/*			Container Vector 			*/
	/****************************************/
	std::cout << "\n\nTesting with " << BLUE << "VECTOR" << RESET << " of int" << std::endl;
	std::vector<int> vectorlist;
	vectorlist.push_back(45);
	vectorlist.push_back(65);
	vectorlist.push_back(87);
	try
	{
		
		print_container(vectorlist);
		// std::vector<int>::const_iterator result = easyfind(vectorlist, 65);
		auto result = easyfind(vectorlist, 65);
		std::cout << "Searching Value" << std::endl;
		std::cout << "Value " << GREEN << *result << RESET <<  " at Address " << CYAN << &(*result) << RESET << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

