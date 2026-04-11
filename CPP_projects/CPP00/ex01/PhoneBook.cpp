/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:21:07 by davli             #+#    #+#             */
/*   Updated: 2024/11/02 17:21:32 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_indexo = 0;
	return;
}

void	PhoneBook::set_information(void)
{
	std::string input;
	if (this->_contacts[this->_index].set_contact() == true)
	{
		if (this->_index == 7)
			this->_index = 0;
		else
			this->_index++;
		if (this->_indexo < 8)
			this->_indexo++;
	}
}

void	PhoneBook::get_information()
{
	int	index;

		std::string input;
		index = 1;
		while (index <= 8)
		{
			std::cout << "|-------------------------------------------|" << std::endl;
			std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;
			this->_contacts[index - 1].get_contact(index);
			std::cout << "|-------------------------------------------|" << std::endl;
			index++;
		}
		std::cout << "Enter contact index. (0 to quit searching)\nIndex: ";
		while (!(std::getline(std::cin, input)) || input.length() > 1 || input.compare("0") < 0 || input.compare("8") > 0 || (std::atoi(input.c_str()) -1 >= this->_indexo))
		{
			if (std::cin.eof() == true)
			{
				std::cout << std::endl;
				std::exit(0);
			}
			if (input.length() != 1 || input.compare("0") < 0 || input.compare("8") > 0)
			{
				std::cin.clear();
				std::cout << "Only digit from 1 to 8.\n";
				std::cout << "Enter contact index. (0 to quit searching)\nIndex: ";
			}
			else if (std::atoi(input.c_str()) >= this->_indexo)
			{
				std::cout << "Only " << this->_indexo << " Contact saved." << std::endl;
				std::cin.clear();
				std::cout << "Enter contact index. (0 to quit searching)\nIndex: ";
			}
		}
		index = std::atoi(input.c_str());
		if (index > 0)
			this->_contacts[index - 1].get_contacts(index);
		else
			std::cout << "Exiting search mode now." << std::endl;
}
