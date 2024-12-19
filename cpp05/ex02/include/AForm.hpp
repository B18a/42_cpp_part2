/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/17 15:14:14 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_isSigned;

	public:
		AForm(const std::string& name, int gradeSign, int gradeExecute);
		AForm(const AForm& other);
		virtual ~AForm(void);
		
		AForm& operator=(const AForm& other);

		std::string getName(void) const;
		int 		getGradeToSign(void) const;
		int 		getGradeToExecute(void) const;
		bool 		getIsSigned(void) const;

		void		beSigned(Bureaucrat& bureau);

/****************************************/
/*				EX02					*/
/****************************************/
		void 			execute(Bureaucrat const & executor) const;
		virtual void 	performExecution(Bureaucrat const & executor) const = 0;

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

		class NotSignedException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};

/****************************************/
/*			Operator Overload			*/
/****************************************/

std::ostream& operator<<(std::ostream& output, const AForm& other);