/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:08 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/17 15:13:13 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/AForm.hpp"

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
/*				Constructor				*/
/****************************************/
AForm::AForm() : _name("noname"), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE), _isSigned(false){}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute) : 
	_name(name), _gradeToSign(gradeSign), _gradeToExecute(gradeExecute), _isSigned(false)
{
	if (_gradeToSign < HIGHEST_GRADE || _gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_gradeToSign > LOWEST_GRADE || _gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}

// Copy Constructor
AForm::AForm(const AForm& other) : 
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(false){}

// Assignment Operator
AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
		this->_isSigned = other.getIsSigned();
	return *this;
}

/****************************************/
/*				Destructor				*/
/****************************************/
AForm::~AForm(void){}

/****************************************/
/*			Getter & Setter				*/
/****************************************/

std::string	AForm::getName(void) const{return _name;}
int			AForm::getGradeToSign(void) const{return _gradeToSign;}
int			AForm::getGradeToExecute(void) const{return _gradeToExecute;}
bool 		AForm::getIsSigned(void) const {return _isSigned;}

/****************************************/
/*			Member Functions			*/
/****************************************/

void		AForm::beSigned(Bureaucrat& bureau)
{
	if(_isSigned)
	{
		throw AlreadySignedException();
	}
	if(bureau.getGrade() > _gradeToSign)
	{
		throw GradeTooLowException();
	}
	_isSigned = true;
}


void AForm::execute(Bureaucrat const & executor) const
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
	performExecution(executor);
}

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "AForm Grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "AForm Grade too low";
}

const char* AForm::AlreadySignedException::what() const noexcept
{
	return "AForm already signed";
}

const char* AForm::NotSignedException::what() const noexcept
{
	return "AForm NOT signed";
}

/****************************************************/
/*				Operator Overload					*/
/****************************************************/

std::ostream& operator<<(std::ostream& output, const AForm& other)
{
	output
	<< "AForm  " 
	<< MAGENTA << other.getName() 
	<< RESET << ", gradeToSign " 
	<< CYAN << other.getGradeToSign() 
	<< RESET << ", gradeToExecute " 
	<< BLUE << other.getGradeToExecute() 
	<< RESET ", is signed "
	<< GREEN << other.getIsSigned() 	
	<< RESET << std::endl;
	return output;
}

