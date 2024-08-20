/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:50:17 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/17 11:10:23 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
    std::ofstream ofs((getTarget() + "_shrubbery").c_str());
    if (ofs) {
        ofs << "  ,d                                                \n"
            << "  88                                                \n"
            << "MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba, ,adPPYba,  \n"
            << "  88    88P'   `Y8 a8P_____88 a8P_____88 I8[    ''  \n"
            << "  88    88         8PP``````` 8PP```````  `'Y8ba,   \n"
            << "  88,   88         `8b,   ,aa `8b,   ,aa aa    ]8I  \n"
            << "  `Y888 88          ``Ybbd8´'  ``Ybbd8´' `'YbbdP'´  "<< std::endl;
        ofs.close();
    }
}
