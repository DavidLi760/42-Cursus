/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:06:39 by davli             #+#    #+#             */
/*   Updated: 2024/11/14 16:31:27 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) {
    int N = 5;
    Zombie* horde = zombieHorde(N, "HordeOfZombie");

    if (horde) {
        for (int i = 0; i < N; ++i) {
            horde[i].announce();
        }
        delete[] horde;
    }

    return 0;
}
