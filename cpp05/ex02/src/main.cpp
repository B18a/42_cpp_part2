/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/19 11:28:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include"../include/ShrubberyCreationForm.hpp"
#include"../include/RobotomyRequestForm.hpp"

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
#define WHITE   "\033[37m"
#define DEFAULT "\033[39m"
#define RESET   "\033[0m" 


int	main(void)
{
	Bureaucrat b1("b1", 150);
	Bureaucrat b2("b2", 40);
	ShrubberyCreationForm f1("Christmas");
	RobotomyRequestForm f2("Robo");
	
	std::cout << b1;
	std::cout << b2;
	std::cout << f1;

	b2.signForm(f2);
	b2.executeForm(f2);
	return (0);
}




