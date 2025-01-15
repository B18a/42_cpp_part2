
#include <iostream>
#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


#ifndef ITNERN_HPP
#define INTERN_HPP

#define NBR_OF_FORMS 3

class Intern
{
	private:
		AForm* makePresidentialPardonForm(std::string target);
		AForm* makeRobotomyRequestForm(std::string target);
		AForm* makeShrubberyCreationForm(std::string target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(std::string name, std::string target);
};
	
#endif
	