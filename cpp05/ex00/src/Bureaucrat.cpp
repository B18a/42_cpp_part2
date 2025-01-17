/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:08 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 10:34:03 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Bureaucrat.hpp"

/****************************************/
/*				Constructor				*/
/****************************************/
Bureaucrat::Bureaucrat() : _name("noname"), _grade(LOWEST_GRADE){}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    _grade = grade;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
		this->_grade = other.getGrade();
	return *this;
}

/****************************************/
/*				Destructor				*/
/****************************************/
Bureaucrat::~Bureaucrat(){}

/****************************************/
/*			Member Functions			*/
/****************************************/
std::string	Bureaucrat::getName(void) const{return _name;}

int			Bureaucrat::getGrade(void) const{return _grade;}

void Bureaucrat::incrementGrade()
{
	if(this->_grade - 1 < HIGHEST_GRADE)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if(this->_grade + 1 > LOWEST_GRADE)
		throw GradeTooLowException();
	else
		this->_grade++;
}

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}

/****************************************************/
/*				Operator Overload					*/
/****************************************************/

std::ostream& operator<<(std::ostream& output, const Bureaucrat& other)
{
	output << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return output;
}

