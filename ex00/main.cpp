/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:03:41 by nopareti          #+#    #+#             */
/*   Updated: 2025/03/27 12:03:41 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
	{
        Bureaucrat bob("Bob", 1);
        std::cout << bob << std::endl;

        bob.incrementGrade();
    }
    catch (const std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat jim("Jim", 151);
    }
    catch (const std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;

        alice.decrementGrade();
    }
    catch (const std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
