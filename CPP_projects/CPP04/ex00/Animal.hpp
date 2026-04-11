/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:01:59 by davli             #+#    #+#             */
/*   Updated: 2024/12/26 19:01:59 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <cmath>
# include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &a);
        Animal  &operator=(const Animal &a);
        virtual ~Animal();
        std::string getType() const;
        virtual void    makeSound() const;
};

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &a);
        WrongAnimal  &operator=(const WrongAnimal &a);
        virtual ~WrongAnimal();
        std::string getType() const;
        void    makeSound() const;
};

#endif
