

#include"../include/Bureaucrat.hpp"
#include <stdexcept>


Bureaucrat::Bureaucrat(void){}
Bureaucrat::~Bureaucrat(void){}



std::string Bureaucrat::getName(void){return _name;}
int	Bureaucrat::getGrade(void){return _grade;}


bool Bureaucrat::setGrade(int value)
{
	if(this->_grade + value > HIGHEST_GRADE || this->_grade + value < LOWEST_GRADE)
	{
		this->_grade += value;
		return 0;
	}
	return 1;
}



int	Bureaucrat::increment_Grade(void)
{
	try
	{
		if(setGrade(1))
			throw GradeTooHighException();
	}
	catch(const GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}


int	Bureaucrat::decrement_Grade(void)
{
	try
	{
		if(setGrade(-1))
			throw GradeTooLowException();
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

