/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:08 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/17 15:13:13 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Form.hpp"

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
Form::Form() : _name("noname"), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE), _isSigned(false){}

Form::Form(const std::string& name, int gradeSign, int gradeExecute) : 
	_name(name), _gradeToSign(gradeSign), _gradeToExecute(gradeExecute), _isSigned(false)
{
	if (_gradeToSign < HIGHEST_GRADE || _gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_gradeToSign > LOWEST_GRADE || _gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other) : 
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(false){}

// Assignment Operator
Form& Form::operator=(const Form& other)
{
	if(this != &other)
		this->_isSigned = other.getIsSigned();
	return *this;
}

/****************************************/
/*				Destructor				*/
/****************************************/
Form::~Form(void){}

/****************************************/
/*			Getter & Setter				*/
/****************************************/

std::string	Form::getName(void) const{return _name;}
int			Form::getGradeToSign(void) const{return _gradeToSign;}
int			Form::getGradeToExecute(void) const{return _gradeToExecute;}
bool 		Form::getIsSigned(void) const {return _isSigned;}

/****************************************/
/*			Member Functions			*/
/****************************************/

void		Form::beSigned(Bureaucrat& bureau)
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

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Form Grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Form Grade too low";
}

const char* Form::AlreadySignedException::what() const noexcept
{
	return "Form already signed";
}

/****************************************************/
/*				Operator Overload					*/
/****************************************************/

std::ostream& operator<<(std::ostream& output, const Form& other)
{
	output
	<< "Form  " 
	<< MAGENTA << other.getName() 
	<< RESET << ", gradeToSign " 
	<< RED 	<< other.getGradeToSign() 
	<< RESET << ", gradeToExecute " 
	<< BLUE << other.getGradeToExecute() 
	<< RESET ", is signed "
	<< GREEN << other.getIsSigned() 	
	<< RESET << std::endl;
	return output;
}

