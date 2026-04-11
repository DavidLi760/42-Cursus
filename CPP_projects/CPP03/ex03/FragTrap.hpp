/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:47:11 by davli             #+#    #+#             */
/*   Updated: 2024/12/06 15:47:39 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    protected:
        const int   FragTrap_HP = 100;
        const int   FragTrap_EP = 100;
        const int   FragTrap_AD = 30;
    public :
        FragTrap();
        FragTrap(std::string name);
        virtual ~FragTrap();
        void    highFivesGuys();
        void    attack(const std::string& target);
};

#endif
