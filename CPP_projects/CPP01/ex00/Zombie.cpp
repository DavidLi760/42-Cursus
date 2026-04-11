/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:38:36 by davli             #+#    #+#             */
/*   Updated: 2024/11/12 15:38:47 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& zombie_name) : _name(zombie_name) {}

Zombie::~Zombie(){
            std::cout << _name << " is destroyed." << std::endl;
        }

void    Zombie::announce() const{
            std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }