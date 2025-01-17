/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:56 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 11:47:55 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm;

#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP

class Bureaucrat
{
	private:
		const std::string _name;
		int		_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		
		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName(void) const;
		int 		getGrade(void) const;
		void 		incrementGrade();
		void		decrementGrade();

/****************************************/
/*				EX01					*/
/****************************************/
		void		signForm(AForm& form);

/****************************************/
/*				EX02					*/
/****************************************/
		void	executeForm(AForm const & form);

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};

#endif

/****************************************/
/*			Operator Overload			*/
/****************************************/

std::ostream& operator<<(std::ostream& output, const Bureaucrat& other);