/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/18 10:41:14 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int		_grade;

	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		
		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName(void) const;
		int 		getGrade(void) const;
		void 		increment_Grade();
		void		decrement_Grade();


/****************************************/
/*				EX01					*/
/****************************************/
		void		signForm(Form& form);

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/
/*
	Inheritance (: public std::exception):

    By inheriting from std::exception, the custom exception becomes 
	compatible with the standard C++ exception-handling mechanism (e.g., try-catch blocks).
    It also provides a default implementation of methods like what().
*/
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};


/****************************************/
/*			Operator Overload			*/
/****************************************/

std::ostream& operator<<(std::ostream& output, const Bureaucrat& other);