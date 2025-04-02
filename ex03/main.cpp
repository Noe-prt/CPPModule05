/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:30:00 by nopareti          #+#    #+#             */
/*   Updated: 2025/04/02 11:29:18 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat president("President", 1);
        AForm* rrf;
        AForm* scf;
        AForm* ppf;
        AForm* invalid;

        std::cout << "\n=== Testing Intern with RobotomyRequestForm ===\n";
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            president.signForm(*rrf);
            president.executeForm(*rrf);
            delete rrf;
        }

        std::cout << "\n=== Testing Intern with ShrubberyCreationForm ===\n";
        scf = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (scf) {
            president.signForm(*scf);
            president.executeForm(*scf);
            delete scf;
        }

        std::cout << "\n=== Testing Intern with PresidentialPardonForm ===\n";
        ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
        if (ppf) {
            president.signForm(*ppf);
            president.executeForm(*ppf);
            delete ppf;
        }

        std::cout << "\n=== Testing Intern with Invalid Form ===\n";
        invalid = someRandomIntern.makeForm("invalid form", "target");
        if (invalid) {
            delete invalid;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
} 