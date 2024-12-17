

#include"../include/Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>


/****************************************/
/*				Constructor				*/
/****************************************/
Bureaucrat::Bureaucrat(std::string name, int grade ): _name(name), _grade(grade)
{
	if(grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if(grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

/****************************************/
/*				Destructor				*/
/****************************************/
Bureaucrat::~Bureaucrat(void){}

/****************************************/
/*			Member Functions			*/
/****************************************/
std::string	Bureaucrat::getName(void) const{return _name;}

int			Bureaucrat::getGrade(void) const{return _grade;}

void Bureaucrat::increment_Grade(void)
{
	if(this->_grade - 1 < HIGHEST_GRADE)
		throw GradeTooHighException();
	else
	{
		this->_grade += -1;
	}
}

void Bureaucrat::decrement_Grade(void)
{
	if(this->_grade + 1 > LOWEST_GRADE)
		throw GradeTooLowException();
	else
	{
		this->_grade += 1;
	}
}

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade too low");
}



/****************************************************/
/*				Operator Overload					*/
/****************************************************/

std::ostream& operator<<(std::ostream& output, const Bureaucrat& other)
{
	output << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (output);
}

