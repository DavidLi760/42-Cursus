/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:46:56 by davli             #+#    #+#             */
/*   Updated: 2024/12/05 14:47:34 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    protected:
        std::string     _name;
        unsigned int    _hitpoints;
        unsigned int    _energypoints;
        unsigned int    _attackdamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif
