/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:20:00 by nopareti          #+#    #+#             */
/*   Updated: 2025/04/02 11:20:00 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 25, 5),
	_target(copy.getTarget())
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	if (this != &assign)
	{
		AForm::operator=(assign);
		_target = assign.getTarget();
	}
	return *this;
}

// Getters / Setters
const std::string& PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat & executor) const
{
	if (executor.getGrade() > getGradeToExecute() || !getIsSigned())
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &form)
{
	out << "Target " << form.getName() <<
	" sign-grade:" << form.getGradeToSign() <<
	" exec-grade:" << form.getGradeToExecute() <<
	" form is signed:" << form.getIsSigned() << std::endl;
	return (out);
} 