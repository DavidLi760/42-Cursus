/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:45:14 by davli             #+#    #+#             */
/*   Updated: 2024/12/30 12:42:54 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
	
// 	ICharacter* me = new Character("me");
	
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
	
// 	ICharacter* bob = new Character("bob");
	
// 	me->use(0, *bob);
// 	me->use(1, *bob);
	
// 	delete bob;
// 	delete me;
// 	delete src;
	
// 	return 0;
// }

int	main()
{
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	Character* me2(me);

	Character* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me2->use(0, *bob);
	me2->use(1, *bob);
	me2->use(2, *bob);
	me2->use(3, *bob);
	me2->use(4, *bob);
	AMateria* removed = me->SaveMateria(3);
	me->unequip(3);

	delete bob;
	delete me;
	delete src;
	delete removed;

	return 0;
}