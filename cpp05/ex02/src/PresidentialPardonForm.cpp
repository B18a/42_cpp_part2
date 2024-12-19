/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/19 10:30:48 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/PresidentialPardonForm.hpp"

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

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm_" + target, DEFAULT_PRESIDENT_SIGN, DEFAULT_PRESIDENT_EXEC), _target(target){}
PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
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

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

/****************************************/
/*			Member Functions			*/
/****************************************/

void PresidentialPardonForm::performExecution(Bureaucrat const & executor) const
{

	std::cout 
	<< MAGENTA << getTarget()
	<< RESET << " has been pardoned by Zaphod Beeblebrox."
	<< RESET << std::endl;

	
	std::cout 
	<< YELLOW << executor.getName() 
	<< RESET << " executed "
	<< MAGENTA << getName() 
	<< RESET << std::endl;
}
