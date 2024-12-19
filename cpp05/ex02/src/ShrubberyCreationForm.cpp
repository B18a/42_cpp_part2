/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/19 08:28:05 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ShrubberyCreationForm.hpp"

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

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target + "_shrubbery", DEFAULT_SIGN, DEFAULT_EXEC), _target(target){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		_target = getTarget();
	}
	return *this;
}

/****************************************/
/*			Getter & Setter				*/
/****************************************/

std::string ShrubberyCreationForm::getTarget()
{
	return _target;
}

/****************************************/
/*			Member Functions			*/
/****************************************/

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout 
	<< YELLOW << executor.getName() 
	<< RESET << " tries to execute Form "
	<< MAGENTA << getName() 
	<< RESET << std::endl;
	if(!getIsSigned() )
		throw NotSignedException();
	if(executor.getGrade() > this->getGradeToExecute())
		throw GradeTooHighException();
	std::cout 
	<< YELLOW << executor.getName() 
	<< RESET << " executes Form "
	<< MAGENTA << getName() 
	<< RESET << std::endl;
}

