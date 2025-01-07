/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:51:34 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/19 11:27:22 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#define DEFAULT_SHRUBBERY_SIGN 145
#define DEFAULT_SHRUBBERY_EXEC 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		
	protected:
		void performExecution(Bureaucrat const & executor) const;
		
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		std::string getTarget() const;

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/
		class OpeningFileException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};