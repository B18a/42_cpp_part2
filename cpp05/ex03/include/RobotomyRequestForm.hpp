/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:45:05 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/19 11:27:18 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#pragma once

#define DEFAULT_ROBO_SIGN 72
#define DEFAULT_ROBO_EXEC 45

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	protected:
		void performExecution(Bureaucrat const & executor) const;
		
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		std::string getTarget() const;

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/
		class RobotomyFailException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};