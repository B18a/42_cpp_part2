/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/19 11:33:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Intern.hpp"

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

/****************************************/
/*		Constructor/Destructor			*/
/****************************************/

Intern::Intern(){}
Intern::~Intern(){}

Intern::Intern(const Intern& other)
{
	(void)other;
}


Intern& Intern::operator=(const Intern& other)
{
	if(this != &other)
	{

	}
	return *this;
}


/****************************************/
/*			Member Functions			*/
/****************************************/

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* (Intern::*funcPTR[NBR_OF_FORMS])(std::string target) = {
		&Intern::makePresidentialPardonForm, 
		&Intern::makeRobotomyRequestForm, 
		&Intern::makeShrubberyCreationForm
	};

	std::string nameOfForms[NBR_OF_FORMS] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};
	int i = 0;
	while (i < NBR_OF_FORMS)
	{
		if(name == nameOfForms[i])
		{
			//std::cout<<"Form exists"<<std::endl;
			return (this->*funcPTR[i])(target);
		}
		i++;
	}
	std::cout<<"Form doesnt exists"<<std::endl;

	return nullptr;
}


/****************************************/
/*		PRIVATE MEMBER FUNCTIONS		*/
/****************************************/

AForm* Intern::makePresidentialPardonForm(std::string target) {
	std::cout << "Intern creates PresidentialPardonForm " << target << std::endl;
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string target) {
	std::cout << "Intern creates RobotomyRequestForm " << target << std::endl;
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubberyCreationForm(std::string target) {
	std::cout << "Intern creates ShrubberyCreationForm " << target << std::endl;
    return new ShrubberyCreationForm(target);
}