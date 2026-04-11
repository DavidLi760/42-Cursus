/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:01:54 by davli             #+#    #+#             */
/*   Updated: 2024/12/26 19:01:55 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
    // std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
    // std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &a)
{
    // std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    // std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &a)
{
    // std::cout << "Animal Copy assignement operator called" << std::endl;
    this->type = a.type;
    return (*this);
}

void    Animal::makeSound() const
{
    std::cout << "Don't know what sound to make..." << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}


WrongAnimal::WrongAnimal() : type("Unknown")
{
    // std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
    // std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
    // std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    // std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a)
{
    // std::cout << "WrongAnimal Copy assignement operator called" << std::endl;
    this->type = a.type;
    return (*this);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Don't know what wrong sound to make..." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}