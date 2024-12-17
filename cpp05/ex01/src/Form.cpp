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
	_name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _isSigned(false)
{
    if (_gradeSign < HIGHEST_GRADE || _gradeExecute < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (_gradeSign < LOWEST_GRADE || _gradeExecute < LOWEST_GRADE)
        throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other) : 
	_name(other._name), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute), _isSigned(other._isSigned){}

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
/*			Member Functions			*/
/****************************************/

std::string	Form::getName(void) const{return _name;}
int			Form::getGradeSign(void) const{return _gradeSign;}
int			Form::getGradeExecute(void) const{return _gradeExecute;}
bool 		Form::getIsSigned(void) const {return _isSigned;}

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}

/****************************************************/
/*				Operator Overload					*/
/****************************************************/

std::ostream& operator<<(std::ostream& output, const Form& other)
{
	output
	<< ", Form  " << other.getName() 
	<< ", gradeSign " << other.getGradeSign() 
	<< ", gradeExecute " << other.getGradeExecute() 
	<< ", is signed " << other.getIsSigned() 	
	<< std::endl;
	return output;
}

