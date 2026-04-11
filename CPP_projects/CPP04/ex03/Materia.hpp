/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:38:26 by davli             #+#    #+#             */
/*   Updated: 2024/12/30 12:38:28 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <cmath>
# include <string>

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &m);
        virtual ~AMateria();
        AMateria& operator=(const AMateria &a);
        
        std::string const & getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& i);
        virtual ~Ice();
        Ice* clone() const;
        Ice& operator=(const Ice &i);
        void    use(ICharacter& target);

};

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& i);
        virtual ~Cure();
        Cure& operator=(const Cure &c);
        Cure* clone() const;
        void    use(ICharacter& target);
};

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria *m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria*   _inventory[4];
    public:
        Character();
        Character(const std::string &name);
        Character(const Character &c);
        Character& operator=(const Character &c);
        ~Character();

        const std::string &getName() const;
        AMateria*   SaveMateria(int idx) const;

        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void    learnMateria(AMateria*) = 0;
        virtual AMateria*   createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*   _inventory[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &m);
        MateriaSource& operator=(const MateriaSource &m);
        ~MateriaSource();

        void    learnMateria(AMateria *m);
        AMateria* createMateria(const std::string &type);
};


#endif
