/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:36:04 by nopareti          #+#    #+#             */
/*   Updated: 2025/03/27 12:36:04 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &assign);
		virtual ~AForm();
		std::string getName() const;
		bool isSigned() const;
		bool getIsSigned() const;
		void setIsSigned(const bool value);
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat & executor) const = 0;
	
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};
	
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &aform);

#endif
	