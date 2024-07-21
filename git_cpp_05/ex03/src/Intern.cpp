/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:14:59 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/17 11:20:53 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include <iostream>

const std::string Intern::formNames[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

const Intern::FormCreator Intern::formCreators[3] = {
    &Intern::createShrubberyCreationForm,
    &Intern::createRobotomyRequestForm,
    &Intern::createPresidentialPardonForm
};

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
    return NULL;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}
