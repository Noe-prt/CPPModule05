/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:48:40 by nopareti          #+#    #+#             */
/*   Updated: 2025/03/27 12:48:40 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), is_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
	{
    if (gradeToSign < 1 || gradeToExecute < 1)
	{
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150)
	{
        throw GradeTooLowException();
    }
}

Form::Form(const Form& copy)
    : name(copy.name), is_signed(copy.is_signed), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {}

Form& Form::operator=(const Form& assign)
{
    if (this != &assign)
	{
        this->is_signed = assign.is_signed;
    }
    return *this;
}

std::string Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return is_signed;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
	{
        throw GradeTooLowException();
    }
    is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName()
       << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}

Form::~Form() {}