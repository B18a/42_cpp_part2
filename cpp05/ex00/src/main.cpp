/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:03 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 11:56:50 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include"../include/Bureaucrat.hpp"
/****************************************/
/*			Text Colors 				*/
/****************************************/

#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m" 

/****************************************************/
/*					EXEPTIONS						*/
/****************************************************/

void    printErrorMessageMessage(const std::exception& e)
{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;    
}

int	main(void)
{

/****************************************************/
/*			Exception Check			            	*/
/****************************************************/
// First exception that is thrown stops the normal flow of
// execution and immediately looks for the nearest matching 
// catch block in the current scope.

	std::cout << BLUE << "Exception Check for Constructor with GRADE 0 (too HIGH)" << RESET << std::endl;
	try 
	{
		Bureaucrat b1("Alice", 0);
	}
	catch (const std::exception& e)  {printErrorMessageMessage(e);}
	
	std::cout << BLUE << "Exception Check for Constructor with GRADE 200 (too LOW)" << RESET << std::endl;
	try 
	{
		Bureaucrat b2("Bob", 200);
	}
	catch (const std::exception& e)  {printErrorMessageMessage(e);}

/****************************************************/
/*		        Increment Exeptions        			*/
/****************************************************/
	std::cout << BLUE << "Increment Exeptions - Incrementing Bureaucrat Grade 1" << RESET << std::endl;
	try {
		Bureaucrat b1("Alice", 1);
		std::cout << b1;
		b1.incrementGrade();
	}
	catch (const std::exception& e) {printErrorMessageMessage(e);}

	std::cout << BLUE << "Decrement Exeptions - Decrementing Bureaucrat Grade 150" << RESET << std::endl;
	try {
		Bureaucrat b1("Alice", 150);
		std::cout << b1;
		b1.decrementGrade();
	}
	catch (const std::exception& e)  {printErrorMessageMessage(e);}

/****************************************************/
/*		        Increment / Decrement     			*/
/****************************************************/
	std::cout << BLUE << "Increment / Decrement" << RESET << std::endl;
	try {
		Bureaucrat b1("Alice2", 55);
		std::cout << b1;
		std::cout << BLUE << "decrementing" << RESET << std::endl;
		b1.decrementGrade();
		std::cout << b1;
		std::cout << BLUE << "incrementing" << RESET << std::endl;
		b1.incrementGrade();
		std::cout << b1;
	}
	catch (const std::exception& e)  {printErrorMessageMessage(e);}
	return (0);
}
