#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm(const std::string &target);
		
		// Destructor
		~PresidentialPardonForm();
		
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		
		// Getters / Setters
		const std::string &getTarget() const;

		void execute(Bureaucrat & executor) const;
		
	private:
		std::string _target;
		
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form);

#endif 