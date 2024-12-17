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
/*				Constructor				*/
/****************************************/
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
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned){}

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
	if(bureau.getGrade() > _gradeToSign)
		throw GradeTooLowException();
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

/****************************************************/
/*				Operator Overload					*/
/****************************************************/

std::ostream& operator<<(std::ostream& output, const Form& other)
{
	output
	<< "Form  " << other.getName() 
	<< ", gradeToSign " << other.getGradeToSign() 
	<< ", gradeToExecute " << other.getGradeToExecute() 
	<< ", is signed " << other.getIsSigned() 	
	<< std::endl;
	return output;
}

