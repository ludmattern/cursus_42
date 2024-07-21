/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/17 10:45:57 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main() {
    // Creating a Bureaucrat with a valid grade and incrementing/decrementing
    try {
        Bureaucrat alice("Alice", 2);
        std::cout << alice << std::endl;
        
        // Test incrementing the grade
        alice.incrementGrade();
        std::cout << "After incrementing: " << alice << std::endl;
        
        // Test decrementing the grade
        alice.decrementGrade();
        std::cout << "After decrementing: " << alice << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception Alice: " << e.what() << std::endl;
    }

    // Creating a Bureaucrat with a grade that is too high
    try {
        Bureaucrat charlie("Charlie", 0); // Should throw an exception
    } catch (const std::exception& e) {
        std::cout << "Exception Charlie: " << e.what() << std::endl;
    }

    // Creating a Bureaucrat with a grade that is too low
    try {
        Bureaucrat dave("Dave", 151); // Should throw an exception
    } catch (const std::exception& e) {
        std::cout << "Exception Dave: " << e.what() << std::endl;
    }

    // Creating a form with valid grades
    try {
        Form formA("Form A", 1, 1);
        std::cout << formA << std::endl;
        
        Bureaucrat bob("Bob", 1);
        bob.signForm(formA);
        std::cout << formA << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception Bob: " << e.what() << std::endl;
    }

    // Attempting to sign a form with insufficient grade
    try {
        Form formB("Form B", 50, 100);
        std::cout << formB << std::endl;
        
        Bureaucrat bob("Bob", 51);
        bob.signForm(formB); // Should fail
        std::cout << formB << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception Bob: " << e.what() << std::endl;
    }

    // Creating a form with a grade that is too high
    try {
        Form formC("Form C", 0, 150); // Should throw an exception during creation
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Creating a form with a grade that is too low
    try {
        Form formD("Form D", 151, 1); // Should throw an exception during creation
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
