/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:03 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 12:06:41 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include"../include/ShrubberyCreationForm.hpp"
#include"../include/RobotomyRequestForm.hpp"
#include"../include/PresidentialPardonForm.hpp"

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
	Bureaucrat bureaucrat1("bureaucrat1", 150);
	Bureaucrat bureaucrat2("bureaucrat2", 40);
	Bureaucrat bureaucrat3("bureaucrat3", 2);
	ShrubberyCreationForm f1("Christmas");
	RobotomyRequestForm f2("Transformation");
	PresidentialPardonForm f3("Marvin");
	
	std::cout << bureaucrat1;
	std::cout << bureaucrat2;
	std::cout << bureaucrat3;
	std::cout << f1;
	std::cout << f2;
	std::cout << f3;

	bureaucrat3.signForm(f2);
	bureaucrat3.signForm(f3);

	bureaucrat1.executeForm(f1);
	bureaucrat3.signForm(f1);
	bureaucrat3.executeForm(f1);

	bureaucrat1.executeForm(f2);
	bureaucrat3.executeForm(f2);

	bureaucrat1.executeForm(f3);
	bureaucrat3.executeForm(f3);


	return (0);
}




