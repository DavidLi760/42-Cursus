/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:05:30 by davli             #+#    #+#             */
/*   Updated: 2024/11/03 15:05:31 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Contact{
	private:
		static std::string	_fields_name[5];
		std::string			_informations[11];

		enum Field {
			FirstName = 0,
			LastName = 1,
			NickName = 2,
			PhoneNumber = 3,
			DarkestSecret = 4
		};
	public:
		Contact(void);

		bool	set_contact();
		void	get_contact(int index);
		void	get_contacts(int index);

};

#endif

