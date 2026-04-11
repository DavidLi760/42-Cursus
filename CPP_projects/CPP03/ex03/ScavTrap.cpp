/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:26:15 by davli             #+#    #+#             */
/*   Updated: 2024/12/05 15:26:29 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "Default Constructor of ScavTrap called" << std::endl;
    _hitpoints = ScavTrap_HP;
    _energypoints = ScavTrap_EP;
    _attackdamage = ScavTrap_AD;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "Constructor of ScavTrap called" << std::endl;
    _hitpoints = ScavTrap_HP;
    _energypoints = ScavTrap_EP;
    _attackdamage = ScavTrap_AD;
};

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor of ScavTrap called" << std::endl;
};

void    ScavTrap::guardGate()
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        std::cout << "ScavTrap " << _name << " is now in GateKeeper Mode" << std::endl;
        _energypoints--;
    }
    std::cout << "Current HP: " << _hitpoints << " | Current Energy: " << _energypoints << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
        _energypoints--;
    }
    std::cout << "Current HP: " << _hitpoints << " | Current Energy: " << _energypoints << std::endl;
}