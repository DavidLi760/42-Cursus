/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:39:08 by davli             #+#    #+#             */
/*   Updated: 2024/12/30 12:39:09 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

AMateria::AMateria()
{
//    std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
    _type = type;
//    std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &m)
{
    _type = m._type;
//    std::cout << "AMateria Copy Constructor called" << std::endl;
}

AMateria::~AMateria()
{
//    std::cout << "AMateria Destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &m)
{
    if (this != &m)
        _type = m._type;
    return (*this);
}

std::string const &AMateria::getType() const
{
    return _type;
}

void    AMateria::use(ICharacter &target)
{
}

Ice::Ice() : AMateria("ice")
{
    this->_type = "ice";
//    std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::Ice(const Ice &i)
{
    this->_type = i._type;
//    std::cout << "Ice Copy Constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &i)
{
    if (this != &i)
        _type = i._type;
    return (*this);
}

Ice::~Ice()
{
//    std::cout << "Ice Destructor called" << std::endl;
}

Ice *Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure::Cure() : AMateria("cure")
{
    this->_type = "cure";
//    std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::Cure(const Cure &c)
{
    this->_type = c._type;
//    std::cout << "Cure Copy Constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &c)
{
    if (this != &c)
        _type = c._type;
    return (*this);
}

Cure::~Cure()
{
//    std::cout << "Cure Destructor called" << std::endl;
}

Cure *Cure::clone() const
{
    return (new Cure());
}

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}

Character::Character()
{
    _name = "Default";
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
    // std::cout << "Character Default Constructor called" << std::endl;
}

Character::Character(const std::string &name)
{
    _name = name;
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
    // std::cout << "Character Constructor called" << std::endl;
}

Character::Character(const Character &c)
{
    _name = c._name;
    for (int i = 0; i < 4; i++)
    {
        if (c._inventory[i] == 0)
            _inventory[i] = 0;
        else
            _inventory[i] = c._inventory[i]->clone();
    }
    // std::cout << "Character Copy Constructor called" << std::endl;
}

Character& Character::operator=(const Character &c)
{
    for (int i = 0; i < 4; i++)
    {
        if (c._inventory[i])
            delete  _inventory[i];
        if (c._inventory[i] == 0)
            _inventory[i] = 0;
        else
            _inventory[i] = c._inventory[i]->clone();
    }
    _name = c._name;
    return (*this);
    // std::cout << "Character Copy assignement operator called" << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
    // std::cout << "Character Destructor called" << std::endl;
}

const std::string&  Character::getName() const
{
    return (_name);
}

void    Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
    }
    std::cout << "Inventory is full" << std::endl;
    free(m);
}

void    Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0)
    {
        if (_inventory[idx])
        {
            std::cout << "Removed Materia at index " << idx << std::endl;
            _inventory[idx] = 0;
            return ;
        }
        std::cout << "Error : No Materia found at index " << idx << std::endl;
        return ;
    }
    std::cout << "Error : Index is invalid " << idx << std::endl;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 4 && idx >= 0)
    {
        if (_inventory[idx])
        {
            _inventory[idx]->use(target);
            return ;
        }
        std::cout << "Error : No Materia found at index " << idx << std::endl;
        return ;
    }
    std::cout << "Error : Index is invalid " << std::endl;
}

AMateria*   Character::SaveMateria(int idx) const
{
    if (idx < 4 && idx >= 0)
    {
        if (_inventory[idx])
            return (_inventory[idx]);
        std::cout << "Error : No Materia found at index " << idx << std::endl;
        return (0);
    }
    std::cout << "Error : Index is invalid " << idx << std::endl;
    return (0);
}

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &m) : IMateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (!m._inventory[i])
            _inventory[i] = 0;
        else
            _inventory[i] = m._inventory[i]->clone();
    }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
        if (!m._inventory[i])
            _inventory[i] = 0;
        else
            _inventory[i] = m._inventory[i]->clone();
    }
    return (*this);
}

void    MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
    }
}

AMateria*   MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i]->getType() == type)
            return (_inventory[i]->clone());
    }
    return (0);
}