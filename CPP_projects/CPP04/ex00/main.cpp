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

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wj = new WrongCat();

	std::cout << wmeta->getType() << " " << std::endl;
	std::cout << wj->getType() << " " << std::endl;
	std::cout << wj->getType() << " " << std::endl;
	wj->makeSound();
	delete i;
	delete j;
	delete wmeta;
	delete wj;
	delete meta;
	return 0;
}
