/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:30:00 by nopareti          #+#    #+#             */
/*   Updated: 2025/04/02 11:29:16 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern
{
    private:
        struct FormType {
            std::string name;
            AForm* (*createForm)(const std::string&);
        };

        static AForm* createShrubberyForm(const std::string& target);
        static AForm* createRobotomyForm(const std::string& target);
        static AForm* createPresidentialForm(const std::string& target);

        static const FormType formTypes[3];

    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& assign);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif 