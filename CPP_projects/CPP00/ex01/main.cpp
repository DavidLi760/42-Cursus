/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:05:35 by davli             #+#    #+#             */
/*   Updated: 2024/11/03 15:05:37 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


int main(void)
{
	PhoneBook 	PhoneBook;
	std::string	command;

	std::cout << "Enter command (ADD, SEARCH, EXIT):" << std::endl;
	std::cout << "$>";
	while (1 && std::getline(std::cin, command))
	{
		if (command.compare("ADD") == 0)
			PhoneBook.set_information();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.get_information();
		else if (command.compare("EXIT") == 0)
			break ;
		std::cout << "Enter command (ADD, SEARCH, EXIT):" << std::endl;
		std::cout << "$>";
	}
	if (std::cin.eof() == true)
		std::cout << std::endl;
	return (0);
}

