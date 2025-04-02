/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:20:00 by nopareti          #+#    #+#             */
/*   Updated: 2025/04/02 11:20:00 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45),
	_target(copy.getTarget())
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	if (this != &assign)
	{
		AForm::operator=(assign);
		_target = assign.getTarget();
	}
	return *this;
}

// Getters / Setters
const std::string& RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat & executor) const
{
	if (executor.getGrade() > getGradeToExecute() || !getIsSigned())
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << "Drilling noises..." << std::endl;
		std::srand(std::time(NULL));
		if (std::rand() % 2 == 0)
			std::cout << _target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "Robotomy failed." << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
	out << "Target " << form.getName() <<
	" sign-grade:" << form.getGradeToSign() <<
	" exec-grade:" << form.getGradeToExecute() <<
	" form is signed:" << form.getIsSigned() << std::endl;
	return (out);
} 