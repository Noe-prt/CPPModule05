/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:20:00 by nopareti          #+#    #+#             */
/*   Updated: 2025/04/02 11:20:00 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat president("President", 1);
        Bureaucrat minister("Minister", 25);
        Bureaucrat clerk("Clerk", 150);

        std::cout << "\n=== Testing ShrubberyCreationForm ===\n";
        ShrubberyCreationForm shrubbery("garden");
        std::cout << shrubbery << std::endl;

        std::cout << "\nTrying to sign with low grade bureaucrat:\n";
        clerk.signForm(shrubbery);

        std::cout << "\nTrying to sign with high grade bureaucrat:\n";
        president.signForm(shrubbery);

        std::cout << "\nTrying to execute with low grade bureaucrat:\n";
        clerk.executeForm(shrubbery);

        std::cout << "\nTrying to execute with high grade bureaucrat:\n";
        president.executeForm(shrubbery);

        std::cout << "\n=== Testing RobotomyRequestForm ===\n";
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;

        std::cout << "\nTrying to sign with low grade bureaucrat:\n";
        clerk.signForm(robotomy);

        std::cout << "\nTrying to sign with high grade bureaucrat:\n";
        president.signForm(robotomy);

        std::cout << "\nTrying to execute with low grade bureaucrat:\n";
        clerk.executeForm(robotomy);

        std::cout << "\nTrying to execute with high grade bureaucrat:\n";
        president.executeForm(robotomy);

        std::cout << "\n=== Testing PresidentialPardonForm ===\n";
        PresidentialPardonForm pardon("Arthur");
        std::cout << pardon << std::endl;

        std::cout << "\nTrying to sign with low grade bureaucrat:\n";
        clerk.signForm(pardon);

        std::cout << "\nTrying to sign with minister:\n";
        minister.signForm(pardon);

        std::cout << "\nTrying to execute with low grade bureaucrat:\n";
        clerk.executeForm(pardon);

        std::cout << "\nTrying to execute with president:\n";
        president.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}