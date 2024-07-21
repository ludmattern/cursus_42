/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/17 11:24:26 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        Intern someRandomIntern;

        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        if (shrubbery) {
            alice.signForm(*shrubbery);
            alice.executeForm(*shrubbery);
            delete shrubbery;
        }

        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        if (robotomy) {
            alice.signForm(*robotomy);
            alice.executeForm(*robotomy);
            delete robotomy;
        }

        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Ford");
        if (pardon) {
            alice.signForm(*pardon);
            alice.executeForm(*pardon);
            delete pardon;
        }

        // Test with a non-existent form
        AForm* unknown = someRandomIntern.makeForm("unknown form", "Target");
        if (unknown) {
            delete unknown;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
