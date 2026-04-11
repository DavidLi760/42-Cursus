/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:37:47 by davli             #+#    #+#             */
/*   Updated: 2024/11/12 15:39:00 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* HeapZombie = newZombie("HeapZombie");
    HeapZombie->announce();

    delete HeapZombie;

    randomChump("StackZombie");
    return (0);
}
