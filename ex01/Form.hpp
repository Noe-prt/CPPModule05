/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:36:04 by nopareti          #+#    #+#             */
/*   Updated: 2025/03/27 12:36:04 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &copy);
		Form &operator=(const Form &assign);
		~Form();
		std::string getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
	
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};
	
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
	