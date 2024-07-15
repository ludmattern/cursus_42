/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:14:03 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 13:56:27 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

void testAnimals()
{
    std::cout << "=== Animal Tests ===" << std::endl;

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
}

void testWrongAnimals()
{
    std::cout << std::endl << "=== WrongAnimal Tests ===" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCatAsWrongAnimal = new WrongCat();
    const WrongCat* wrongCat = new WrongCat();

    std::cout << "WrongAnimal _type: " << wrongMeta->getType() << std::endl;
    std::cout << "WrongCat (as WrongAnimal) _type: " << wrongCatAsWrongAnimal->getType() << std::endl;
    std::cout << "WrongCat _type: " << wrongCat->getType() << std::endl;

    std::cout << "WrongAnimal sound: ";
    wrongMeta->makeSound();

    std::cout << "WrongCat (as WrongAnimal) sound: ";
    wrongCatAsWrongAnimal->makeSound();

    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongCatAsWrongAnimal;
    delete wrongCat;
}


int main()
{
    testAnimals();
    testWrongAnimals();
    return (0);
}
