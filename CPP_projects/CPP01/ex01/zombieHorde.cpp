/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:06:56 by davli             #+#    #+#             */
/*   Updated: 2024/11/12 16:07:03 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string _name){
    if (N <= 0)
        return (nullptr);

    Zombie* horde = new Zombie[N];

    int i = 0;
    while (i < N){
        horde[i++].setName(_name);
    }
    return horde;
}