/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:03:42 by nopareti          #+#    #+#             */
/*   Updated: 2025/03/27 12:03:42 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &assign);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif