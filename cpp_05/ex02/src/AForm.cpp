/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:37:28 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/17 10:49:24 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

const std::string& AForm::getTarget() const {
    return _target;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!_isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw GradeTooLowException();
    }
    action();
}

void AForm::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() << ", requires grade " << form.getGradeToSign()
       << " to sign, grade " << form.getGradeToExecute() << " to execute, "
       << (form.isSigned() ? "is signed." : "is not signed.") << ", target: " << form.getTarget();
    return os;
}
