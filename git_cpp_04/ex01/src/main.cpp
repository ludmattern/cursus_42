/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:14:03 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 16:28:39 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

void testAnimals()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Animal _type: " << meta->getType() << std::endl;
    std::cout << "Animal _type: " << dog->getType() << std::endl;
    std::cout << "Animal _type: " << cat->getType() << std::endl;

    std::cout << "Animal sound: ";
    meta->makeSound();

    std::cout << "Animal sound: ";
    dog->makeSound();

    std::cout << "Animal sound: ";
    cat->makeSound();

    delete meta;
    delete dog;
    delete cat;

    Dog basic; {Dog tmp = basic;}
}

int main()
{
    testAnimals();
    return (0);
}
