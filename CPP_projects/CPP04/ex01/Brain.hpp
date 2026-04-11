/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:59:38 by davli             #+#    #+#             */
/*   Updated: 2024/12/26 19:01:08 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &b);
        Brain &operator=(const Brain &b);
        ~Brain();
        void    modifyIdea(int i, const std::string str);
        void    printIdea(int i);
};


#endif
