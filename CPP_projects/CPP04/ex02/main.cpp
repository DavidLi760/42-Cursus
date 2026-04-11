/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:45:14 by davli             #+#    #+#             */
/*   Updated: 2024/12/20 14:48:42 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	// Animal	test_instance;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal*	animals[100];
	Dog	dog1;
	dog1.printBrain(0);
	dog1.modifyBrain(0, "Idea in dog1");
	dog1.printBrain(0);
	dog1.modifyBrain(0, "Another idea in dog1");
	dog1.printBrain(0);
	for (int i = 0; i < 50; ++i)
	{
		animals[i] = new Dog();
		animals[i + 50] = new Cat();
	}

	for (int i = 0; i < 100; ++i)
		animals[i]->makeSound();

	for (int i = 0; i < 100; ++i)
		delete animals[i];
	delete j;
	delete i;
	return (0);
}