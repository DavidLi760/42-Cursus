/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:59:24 by davli             #+#    #+#             */
/*   Updated: 2024/12/26 18:59:34 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = "Idea " + std::to_string(i);
    // std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = b.ideas[i];
    // std::cout << "Brain Copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &b)
{
    if (this != &b)
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = b.ideas[i];
    // std::cout << "Brain Copy assignement operator called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    // std::cout << "Brain Destructor called" << std::endl;
}

void    Brain::modifyIdea(int i, const std::string str)
{
    if (i >= 0 && i < 100)
        ideas[i] = str;
}

void    Brain::printIdea(int i)
{
    if (i >= 0 && i < 100)
        std::cout << "Brain Idea " << i << ": " << ideas[i] << std::endl;
}