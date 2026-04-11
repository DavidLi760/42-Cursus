/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:46:31 by davli             #+#    #+#             */
/*   Updated: 2024/12/05 14:46:49 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
    DiamondTrap b("Bob");

    std::cout << std::endl;
    b.whoAmI();
    b.attack("noob");
    b.beRepaired(10);
    b.takeDamage(50);
    b.takeDamage(50);
    b.takeDamage(50);
    b.attack("noob");
    b.attack("noob");
    b.attack("noob");
    std::cout << std::endl;
    return (0);
}
