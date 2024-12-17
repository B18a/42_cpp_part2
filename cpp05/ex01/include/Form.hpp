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

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Form
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExecute;
		bool				_isSigned;

	public:
		Form(const std::string& name, int gradeSign, int gradeExecute);
		~Form(void);
		Form(const Form& other);
		Form& operator=(const Form& other);

		std::string getName(void) const;
		int 		getGradeSign(void) const;
		int 		getGradeExecute(void) const;
		bool 		getIsSigned(void) const;

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


/****************************************/
/*			Operator Overload			*/
/****************************************/

std::ostream& operator<<(std::ostream& output, const Form& other);