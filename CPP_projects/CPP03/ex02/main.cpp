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

#include "FragTrap.hpp"

int	main()
{
    FragTrap    b("Bob");

    std::cout << std::endl;
    b.highFivesGuys();
    b.attack("Steve");
    b.beRepaired(10);
    b.takeDamage(50);
    b.takeDamage(50);
    b.takeDamage(50);
    b.attack("Steve");
    std::cout << std::endl;
    return (0);
}
