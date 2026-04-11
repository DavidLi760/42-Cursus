/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:42:49 by davli             #+#    #+#             */
/*   Updated: 2024/11/13 18:43:25 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string		str = "HI_THIS_IS_BRAIN";
	std::string*	strp = &str;
	std::string&	strref = str;

	std::cout << &str << std::endl;
	std::cout << strp << std::endl;
	std::cout << &strref << std::endl;

	std::cout << str << std::endl;
	std::cout << *strp << std::endl;
	std::cout << strref << std::endl;
	return (0);
}
