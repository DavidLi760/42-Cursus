/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:05:20 by davli             #+#    #+#             */
/*   Updated: 2024/11/03 15:05:23 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::_fields_name[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};


Contact::Contact()
{
	int	i = FirstName;
	while (i <= DarkestSecret)
		this->_informations[i++] = std::string();
	return;
}

bool	Contact::set_contact()
{
	int	i = FirstName;
	while (i <= DarkestSecret)
	{
		std::cout << Contact::_fields_name[i] << " : ";
		while (!(std::getline(std::cin, this->_informations[i])) || this->_informations[i].length() == 0)
		{
			if (std::cin.eof() == true)
			{
				std::cout << std::endl;
				std::exit(0);
			}
			else if (this->_informations[i].length() == 0)
			{
				this->_informations[i].clear();
				std::cout << "Field can't be empty" << std::endl;
				std::cout << Contact::_fields_name[i] << " : ";
			}
		}
		i++;
	}
	std::cout << "Contact added successfully." << std::endl;
	return (true);
}

void	Contact::get_contact(int index)
{
	int	i;

	i = FirstName;
	std::cout << "|" << std::setw(10) << index;
	while (i <= NickName)
	{
		std::cout << "|";
		if (this->_informations[i].length() > 10)
			std::cout << this->_informations[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_informations[i];
		i++;
	}
	std::cout << "|" << std::endl;
}

void	Contact::get_contacts(int index)
{
	int	i;

	i = FirstName;
	while (i <= DarkestSecret)
	{
		if (i == 0)
			std::cout << "First Name : ";
		if (i == 1)
			std::cout << "Lase Name : ";
		if (i == 2)
			std::cout << "Nickname : ";
		if (i == 3)
			std::cout << "Phone number : ";
		if (i == 4)
			std::cout << "Darkest Secret : ";
		std::cout << this->_informations[i] << std::endl;
		i++;
	}
	std::cout << std::endl;
}