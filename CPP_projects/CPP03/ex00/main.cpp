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

#include "ClapTrap.hpp"

int	main()
{
    ClapTrap    b("Bob");

    std::cout << std::endl;
    b.attack("Steve");
    b.takeDamage(9);
    b.beRepaired(2);
    b.beRepaired(2);
    b.attack("Steve");
    b.attack("Steve");
    b.attack("Steve");
    b.attack("Steve");
    b.attack("Steve");
    b.attack("Steve");
    b.attack("Steve");
    b.beRepaired(2);
    b.takeDamage(5);
    std::cout << std::endl;
    return (0);
}
