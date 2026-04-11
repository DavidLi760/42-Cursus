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

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &c);
        Cat &operator=(const Cat &c);
        virtual ~Cat();
        std::string getType() const;
        void    makeSound() const;
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &c);
        WrongCat &operator=(const WrongCat &c);
        virtual ~WrongCat();
        std::string getType() const;
        using   WrongAnimal::makeSound;
};

#endif
