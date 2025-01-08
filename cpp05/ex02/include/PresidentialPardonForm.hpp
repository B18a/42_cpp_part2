/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:51:34 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/19 11:27:22 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#define DEFAULT_PRESIDENT_SIGN 25
#define DEFAULT_PRESIDENT_EXEC 5

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		
	protected:
		void performExecution(Bureaucrat const & executor) const;
		
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		std::string getTarget() const;
};

#endif
