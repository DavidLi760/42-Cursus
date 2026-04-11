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

#include "ScavTrap.hpp"

int	main()
{
    ScavTrap    b("Bob");

    std::cout << std::endl;
    b.guardGate();
    b.attack("Steve");
    b.beRepaired(10);
    b.takeDamage(50);
    b.takeDamage(50);
    b.takeDamage(50);
    std::cout << std::endl;
    return (0);
}
