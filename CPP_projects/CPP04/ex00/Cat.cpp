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
    // std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &c) : Animal(c.type)
{
    // std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    // std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &c)
{
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

WrongCat& WrongCat::operator=(const WrongCat &c)
{
    // std::cout << "WrongCat Copy assignement operator called" << std::endl;
    this->type = c.type;
    return (*this);
}

std::string WrongCat::getType() const
{
    return this->type;
}