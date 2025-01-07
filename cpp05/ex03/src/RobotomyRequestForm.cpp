/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/19 10:30:48 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/RobotomyRequestForm.hpp"

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

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm_" + target, DEFAULT_ROBO_SIGN, DEFAULT_ROBO_EXEC), _target(target){}
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
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

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

/****************************************/
/*			Member Functions			*/
/****************************************/

void RobotomyRequestForm::performExecution(Bureaucrat const & executor) const
{
	int gamble;
    std::srand(time(0));
    //std::srand(std::time(0));
	gamble = std::rand() % 2;

	if(gamble)
	{
		std::cout 
		<< RESET << "BEEP BE BE BEEEP "
		<< MAGENTA << getTarget()
		<< RESET << " has been robotomized successfully 50% of the time"
		<< RESET << std::endl;
	}
	else
		throw RobotomyFailException();
	
	std::cout 
	<< YELLOW << executor.getName() 
	<< RESET << " executed "
	<< MAGENTA << getName() 
	<< RESET << std::endl;
}

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* RobotomyRequestForm::RobotomyFailException::what() const noexcept
{
	return "Robotomy Failed";
}