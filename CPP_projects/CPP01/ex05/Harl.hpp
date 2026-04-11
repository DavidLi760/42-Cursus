/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:13:07 by davli             #+#    #+#             */
/*   Updated: 2024/11/14 17:14:03 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <map>

class Harl{
    private:
        void    debug();
        void    info();
        void    warning();
        void    error();
    public:
        void    complain(std::string level);
};

#endif
