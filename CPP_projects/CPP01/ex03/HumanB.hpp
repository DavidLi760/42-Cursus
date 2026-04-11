/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:39:38 by davli             #+#    #+#             */
/*   Updated: 2024/11/14 14:39:39 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB{
    private:
        std::string _name;
        Weapon*     weapon;

    public:
        HumanB(const std::string& name);
        void    attack();
        void    setWeapon(Weapon& weapon);
};

#endif

