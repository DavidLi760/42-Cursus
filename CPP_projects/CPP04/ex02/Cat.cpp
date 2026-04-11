/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:01:47 by davli             #+#    #+#             */
/*   Updated: 2024/12/26 19:01:47 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    // std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &c) : Animal(c.type)
{
    brain = new Brain(*c.brain);
    // std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    // std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &c)
{
    brain = new Brain(*c.brain);
    // std::cout << "Cat Copy assignement operator called" << std::endl;
    this->type = c.type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Meow, Meowww..." << std::endl;
}

std::string    Cat::getType() const
{
    return this->type;
}

void    Cat::modifyBrain(int i, const std::string str) const
{
    brain->modifyIdea(i, str);
}

void    Cat::printBrain(int i) const
{
    brain->printIdea(i);
}



WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    // std::cout << "WrogCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &c) : WrongAnimal(c.type)
{
    // std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    // std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &a)
{
    // std::cout << "WrongCat Copy assignement operator called" << std::endl;
    this->type = a.type;
    return (*this);
}