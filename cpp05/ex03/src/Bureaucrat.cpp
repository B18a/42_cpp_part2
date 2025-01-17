/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:08 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 10:55:20 by ajehle           ###   ########.fr       */
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
Bureaucrat::Bureaucrat() : _name("noname"), _grade(LOWEST_GRADE){}

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
	output
	<< YELLOW << other.getName() 
	<< RESET << ", bureaucrat grade " 
	<< GREEN << other.getGrade() 
	<< RESET << std::endl;
	return output;
}

/****************************************/
/*				EX01					*/
/****************************************/
void		Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e )
	{
		std::cerr 
        << RED << "Error: " 
		<< YELLOW << getName()
		<< RESET << " couldn`t sign " 
		<< MAGENTA << form.getName() 
		<< RESET << " because " 
		<< CYAN << e.what() 
		<< RESET << std::endl;
		return;
	}
	std::cout 
	<< YELLOW << getName()
	<< RESET << " signed "
	<< MAGENTA << form.getName() 
	<< RESET << std::endl;
}

/****************************************/
/*				EX02					*/
/****************************************/

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr 
		<< RED << "Error: " 
		<< YELLOW << getName()
		<< RESET << " couldn`t execute " 
		<< MAGENTA << form.getName() 
		<< RESET << " because " 
		<< CYAN << e.what() 
		<< RESET << std::endl;
	}	
}