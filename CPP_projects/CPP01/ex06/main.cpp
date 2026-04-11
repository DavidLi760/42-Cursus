/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:32:48 by davli             #+#    #+#             */
/*   Updated: 2024/11/15 16:32:49 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    int level = 0;
    if (argc != 2)
        return (std::cout << "./harlFilter <level>" << std::endl, 0);
    std::string lvl = argv[1];
    if (lvl == "DEBUG")
        level = 1;
    else if (lvl == "INFO")
        level = 2;
    else if (lvl == "WARNING")
        level = 3;
    else if (lvl == "ERROR")
        level = 4;
    filtering(level);
    return (0);
}