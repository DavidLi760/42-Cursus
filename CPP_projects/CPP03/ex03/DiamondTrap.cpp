/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:03:29 by davli             #+#    #+#             */
/*   Updated: 2024/12/06 16:03:36 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    std::cout << "Default Constructor of DiamondTrap called" << std::endl;
    this->_name = "default_clap_name";
    _hitpoints = FragTrap::FragTrap_HP;
    _energypoints = ScavTrap::ScavTrap_EP;
    _attackdamage = FragTrap::FragTrap_AD;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor of DiamondTrap called" << std::endl;
    this->_name = name;
    ClapTrap::_name = std::string(name) + "_clap_name";
    _hitpoints = FragTrap::FragTrap_HP;
    _energypoints = ScavTrap::ScavTrap_EP;
    _attackdamage = FragTrap::FragTrap_AD;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor of DiamondTrap called" << std::endl;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
