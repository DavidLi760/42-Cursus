/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:24 by davli             #+#    #+#             */
/*   Updated: 2024/11/12 16:10:28 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Zombie{
    private:
        std::string _name;
    
    public:
        Zombie();
        ~Zombie();

        void    announce() const;
        void    setName(const std::string& name);
};

Zombie* zombieHorde(int N, std::string _name);

#endif
