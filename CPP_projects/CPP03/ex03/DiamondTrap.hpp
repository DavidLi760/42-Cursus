/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:03:40 by davli             #+#    #+#             */
/*   Updated: 2024/12/06 16:05:04 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
    public :
        DiamondTrap();
        DiamondTrap(std::string name);
        virtual ~DiamondTrap();
        using   ScavTrap::attack;
        void    whoAmI();
};

#endif
