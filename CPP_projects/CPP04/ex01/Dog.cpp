/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:01:50 by davli             #+#    #+#             */
/*   Updated: 2024/12/26 19:01:51 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    brain = new Brain();
    // std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &d) : Animal(d.type)
{
    brain = new Brain(*d.brain);
    // std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    // std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &d)
{
    brain = new Brain(*d.brain);
    // std::cout << "Dog Copy assignement operator called" << std::endl;
    this->type = d.type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Woof, woof !" << std::endl;
}

std::string    Dog::getType() const
{
    return this->type;
}

void    Dog::modifyBrain(int i, const std::string str) const
{
    brain->modifyIdea(i, str);
}

void    Dog::printBrain(int i) const
{
    brain->printIdea(i);
}