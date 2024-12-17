/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:08 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/17 18:03:14 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Form.hpp"

/****************************************/
/*				Constructor				*/
/****************************************/
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(LOWEST_GRADE)
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

void Bureaucrat::increment_Grade()
{
	if(this->_grade - 1 < HIGHEST_GRADE)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrement_Grade()
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

/****************************************/
/*				EX01					*/
/****************************************/
void		Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e )
	{
		std::cout << getName() << " couldn`t sign " << form.getName() << " because " << e.what() << std::endl;
		// throw;
		return;
	}
	std::cout << getName() << " signed " << form.getName() << std::endl;
}