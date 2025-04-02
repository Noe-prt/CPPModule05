#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm(const std::string &target);
		
		// Destructor
		~ShrubberyCreationForm();
		
		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		
		// Getters / Setters
		const std::string &getTarget() const;

		void execute(Bureaucrat & executor) const;
		
	private:
		std::string _target;
		
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shrubbery);

#endif