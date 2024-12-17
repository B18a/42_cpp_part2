

#include"../include/Bureaucrat.hpp"
#include <stdexcept>


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
std::string Bureaucrat::getName(void){return _name;}

int	Bureaucrat::getGrade(void){return _grade;}

bool Bureaucrat::setGrade(int value)
{
	if(this->_grade + value > HIGHEST_GRADE || this->_grade + value < LOWEST_GRADE)
	{
		this->_grade += value;
		return 0;
	}
	// hier throw exception
	return 1;
}

// int	Bureaucrat::increment_Grade(void)
// {
// 	try
// 	{
// 		if(setGrade(1))
// 			throw GradeTooHighException();
// 	}
// 	catch(const GradeTooHighException& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	return 0;
// }

// int	Bureaucrat::decrement_Grade(void)
// {
// 	try
// 	{
// 		if(setGrade(-1))
// 			throw GradeTooLowException();
// 	}
// 	catch(const GradeTooLowException& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	return 0;
// }

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


