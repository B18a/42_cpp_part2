/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:51:34 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/18 14:51:56 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#define DEFAULT_SIGN 137
#define DEFAULT_EXEC 145

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		std::string getTarget();

		void execute(Bureaucrat const & executor) const;
};