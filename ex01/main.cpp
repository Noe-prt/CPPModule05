/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:05:00 by nopareti          #+#    #+#             */
/*   Updated: 2025/03/27 13:05:00 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat highRank("Alice", 1);
        Bureaucrat lowRank("Bob", 150);

        std::cout << highRank << std::endl;
        std::cout << lowRank << std::endl;

        Form easyForm("Basic Form", 100, 50);
        Form hardForm("Secret Form", 1, 1);

        std::cout << easyForm << std::endl;
        std::cout << hardForm << std::endl;

        lowRank.signForm(easyForm);

        highRank.signForm(easyForm);

        Form invalidForm("Invalid Form", 0, 151);

    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
