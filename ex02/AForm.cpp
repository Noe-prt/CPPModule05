/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:48:40 by nopareti          #+#    #+#             */
/*   Updated: 2025/03/27 12:48:40 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), is_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
	{
    if (getGradeToSign() < 1 || getGradeToExecute() < 1)
	{
        throw GradeTooHighException();
    }
    if (getGradeToSign() > 150 || getGradeToExecute() > 150)
	{
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& copy)
    : name(copy.getName()), is_signed(copy.getIsSigned()), gradeToSign(copy.getGradeToSign()),
        gradeToExecute(copy.getGradeToExecute()) {}

AForm& AForm::operator=(const AForm& assign)
{
    if (this != &assign)
	{
        this->is_signed = assign.getIsSigned();
    }
    return *this;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::isSigned() const
{
    return is_signed;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

bool AForm::getIsSigned() const
{
    return is_signed;
}

void AForm::setIsSigned(const bool value)
{
    is_signed = value;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > getGradeToSign())
	{
        throw GradeTooLowException();
    }
    setIsSigned(true);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& aform)
{
    os << "Form: " << aform.getName()
       << ", Signed: " << (aform.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << aform.getGradeToSign()
       << ", Grade to Execute: " << aform.getGradeToExecute();
    return os;
}

AForm::~AForm() {}