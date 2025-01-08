/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/17 15:14:14 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

#ifndef FORM_HPP
#define  FORM_HPP

class Form
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_isSigned;

	public:
		Form(const std::string& name, int gradeSign, int gradeExecute);
		Form(const Form& other);
		~Form(void);
		
		Form& operator=(const Form& other);

		std::string getName(void) const;
		int 		getGradeToSign(void) const;
		int 		getGradeToExecute(void) const;
		bool 		getIsSigned(void) const;

		void		beSigned(Bureaucrat& bureau);
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

		class AlreadySignedException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};

#endif

/****************************************/
/*			Operator Overload			*/
/****************************************/

std::ostream& operator<<(std::ostream& output, const Form& other);