/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:46:58 by davli             #+#    #+#             */
/*   Updated: 2024/12/06 15:47:07 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default Constructor of FragTrap called" << std::endl;
    _hitpoints = FragTrap_HP;
    _energypoints = FragTrap_EP;
    _attackdamage = FragTrap_AD;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor of FragTrap called" << std::endl;
    _hitpoints = FragTrap_HP;
    _energypoints = FragTrap_EP;
    _attackdamage = FragTrap_AD;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor of FragTrap called" << std::endl;
}

void    FragTrap::highFivesGuys()
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        std::cout << "FragTrap " << _name << " is requesting a High Fives" << std::endl;
        _energypoints--;
    }
    std::cout << ClapTrap::_energypoints << " energy points left" << std::endl;
}

void    FragTrap::attack(const std::string& target)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackdamage << " points of damage!" << std::endl; 
        _energypoints--;
    }
    std::cout << "Current HP: " << _hitpoints << " | Current Energy: " << _energypoints << std::endl;
}