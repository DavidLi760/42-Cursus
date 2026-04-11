/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:07 by davli             #+#    #+#             */
/*   Updated: 2024/11/12 16:07:21 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed") {}

Zombie::~Zombie(){
            std::cout << _name << " is destroyed." << std::endl;
}

void    Zombie::setName(const std::string& _name)
{
    this->_name = _name;
}

void    Zombie::announce() const{
            std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }