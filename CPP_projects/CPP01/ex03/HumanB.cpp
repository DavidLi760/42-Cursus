/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:36:45 by davli             #+#    #+#             */
/*   Updated: 2024/11/14 14:36:46 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

Weapon* weapon = nullptr;

HumanB::HumanB(const std::string& name) : _name(name) {};

void    HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
}

void    HumanB::attack(){
    std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
}
