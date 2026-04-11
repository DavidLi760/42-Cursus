/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:47:40 by davli             #+#    #+#             */
/*   Updated: 2024/12/05 14:47:53 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
    std::cout << "Default Constructor of ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
    std::cout << "Constructor of ClapTrap called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor of ClapTrap called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
        _energypoints--;
    }
    std::cout << "Current HP: " << _hitpoints << " | Current Energy: " << _energypoints << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitpoints < amount)
        _hitpoints = 0;
    else
        _hitpoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    std::cout << "Current HP: " << _hitpoints << " | Current Energy: " << _energypoints << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        _hitpoints += amount;
        std::cout << "ClapTrap " << _name << " gets " << amount << " hitpoints back from repairing!" << std::endl;
        _energypoints--;
    }
    std::cout << "Current HP: " << _hitpoints << " | Current Energy: " << _energypoints << std::endl;
}