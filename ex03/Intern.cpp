/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:30:00 by nopareti          #+#    #+#             */
/*   Updated: 2025/04/02 11:35:18 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
    (void)copy;
}

Intern& Intern::operator=(const Intern& assign) {
    (void)assign;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

const Intern::FormType Intern::formTypes[3] = {
    {"shrubbery creation", Intern::createShrubberyForm},
    {"robotomy request", Intern::createRobotomyForm},
    {"presidential pardon", Intern::createPresidentialForm}
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (int i = 0; i < 3; i++) {
        if (formTypes[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formTypes[i].createForm(target);
        }
    }
    std::cerr << "Error: Form type '" << formName << "' not found" << std::endl;
    return NULL;
} 