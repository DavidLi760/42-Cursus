/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:37:56 by davli             #+#    #+#             */
/*   Updated: 2024/11/12 15:40:53 by davli            ###   ########.fr       */
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
        Zombie(const std::string& zombie_name);
        
        void    announce() const;
        ~Zombie();
};
    Zombie* newZombie(std::string _name);
    void    randomChump(std::string _name);

#endif