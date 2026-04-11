/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:25:36 by davli             #+#    #+#             */
/*   Updated: 2024/12/05 15:26:07 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    protected:
        const int   ScavTrap_HP = 100;
        const int   ScavTrap_EP = 50;
        const int   ScavTrap_AD = 20;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        virtual ~ScavTrap();
        void    guardGate();
        void    attack(const std::string& target);
};

#endif
