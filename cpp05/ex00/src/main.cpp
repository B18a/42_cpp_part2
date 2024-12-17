/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/17 15:13:05 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include"../include/Bureaucrat.hpp"

/****************************************************/
/*					EXEPTIONS						*/
/****************************************************/

void createBureaucrat() {
    Bureaucrat b1("Alice", 0);
}

int	main(void)
{

/****************************************************/
/*			Exception Check			            	*/
/****************************************************/
// First exception that is thrown stops the normal flow of
// execution and immediately looks for the nearest matching 
// catch block in the current scope.

    std::cout << "Exception Check" << std::endl;
    try 
    {
        Bureaucrat b2("Bob", 200);
        Bureaucrat b1("Alice", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e) 
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) 
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Caught an unknown exception: " << e.what() << std::endl;
    }


/****************************************************/
/*		 Exception get thrown to the caller			*/
/****************************************************/
std::cout << "Exception get thrown to the caller" << std::endl;
    try 
    {
        createBureaucrat();
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

/****************************************************/
/*		        Increment Exeptions        			*/
/****************************************************/
std::cout << "Increment Exeptions" << std::endl;
    try {
        Bureaucrat b1("Alice", 1);
        b1.increment_Grade();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        Bureaucrat b1("Alice", 150);
        std::cout << b1;
        b1.decrement_Grade();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return (0);
}




