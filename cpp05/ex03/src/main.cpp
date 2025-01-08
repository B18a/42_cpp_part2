/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/19 11:44:42 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include"../include/ShrubberyCreationForm.hpp"
#include"../include/RobotomyRequestForm.hpp"
#include"../include/PresidentialPardonForm.hpp"
#include"../include/Intern.hpp"

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
	Intern someRandomIntern;
	
	AForm* form;

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if(form)
		delete form;
	
	form= someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	if(form)
		delete form;
	
	form= someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if(form)
		delete form;
	
	form= someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	if(form)
		delete form;

	return (0);
}




