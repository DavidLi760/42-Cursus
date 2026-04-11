/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:01:41 by davli             #+#    #+#             */
/*   Updated: 2024/12/26 19:01:43 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <cmath>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain*  brain;
    public:
        Cat();
        Cat(const Cat &c);
        Cat &operator=(const Cat &a);
        virtual ~Cat();
        std::string getType() const;
        void    makeSound() const;
        void    modifyBrain(int i, const std::string str) const;
        void    printBrain(int i) const;
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &c);
        WrongCat &operator=(const WrongCat &a);
        virtual ~WrongCat();
        std::string getType() const;
        using   WrongAnimal::makeSound;
};

#endif
