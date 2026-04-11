/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:01:24 by davli             #+#    #+#             */
/*   Updated: 2024/12/26 19:01:36 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <cmath>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain*  brain;
    public:
        Dog();
        Dog(const Dog &d);
        Dog &operator=(const Dog &a);
        virtual ~Dog();
        std::string getType() const;
        void    makeSound() const;
        void    modifyBrain(int i, const std::string str) const;
        void    printBrain(int i) const;
};

#endif
