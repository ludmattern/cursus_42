/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:14:03 by lmattern          #+#    #+#             */
/*   Updated: 2024/06/25 19:46:32 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

void testAnimals()
{
    //won't compile
    //const AAnimal* meta = new AAnimal();
    //const AAnimal test;

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << "Animal _type: " << dog->getType() << std::endl;
    std::cout << "Animal _type: " << cat->getType() << std::endl;

    std::cout << "Animal sound: ";
    dog->makeSound();

    std::cout << "Animal sound: ";
    cat->makeSound();

    delete dog;
    delete cat;

    Dog* dog1 = new Dog();
    dog1->addIdea("Chase the cat", 0);
    dog1->addIdea("Bark at the mailman", 1);
    dog1->addIdea("Fetch the ball", 2);

    std::cout << "\nDog1's Ideas:" << std::endl;
    dog1->showIdeas();

    Dog* dog2 = new Dog(*dog1);

    std::cout << "\nDog2's Ideas (after copying from Dog1):" << std::endl;
    dog2->showIdeas();

    dog2->addIdea("Dig a hole", 1);

    std::cout << "\nDog1's Ideas (after modifying Dog2):" << std::endl;
    dog1->showIdeas();

    delete dog1;
    
    std::cout << "\nDog2's Ideas (after modification and destruction of Dog1):\n" << std::endl;
    dog2->showIdeas();

    delete dog2;
}

int main()
{
    testAnimals();
    return (0);
}
