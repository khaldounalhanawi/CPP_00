/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:02:54 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/02 10:02:55 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "PhoneBook_helpers.hpp"
#include "PhoneBook_print.hpp"
#include "colors.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

Contact	PhoneBook::GetContact (int id) const
{
	return (this->_ContactList[id]);
}

void	PhoneBook::AddBook(int IndexPosition)
{
	Contact		NewContact;
	std::string	buffer;
	int			i;

	NewContact.id = IndexPosition;
	i = 0;
	while (i < CategoryCount)
	{
		std::cout<< RED
				 <<"Please enter your "
				 << names[i]
				 << " :"
				 << RESET
				 <<std::endl;
		buffer.clear ();
		while (buffer.empty ())
			if (!std::getline (std::cin, buffer))
				break;
		NewContact.SetField (i, buffer);
		i ++;
	}
	this->_ContactList[IndexPosition] = NewContact;
	std::cout<< GREEN
			 <<"New contact has been saved!"
			 << RESET
			 <<std::endl;
	return;
}

void	PhoneBook::search(void) const
{
	std::string	headers[4] = {"Index", "First name", "Last name", "Nickname"};
	int		id;

	if (this->_ContactList[0].id == -1)
	{
		std::cout<< RESET
				 << "PhoneBook is empty! "
					"please use the 'add' function to fill it."
				 << std::endl;
		return;
	}
	PrintTable (4, 10, this, headers);
	while (1)
	{
		id = GetIdInput ();
		if (id == -2)
			return;
		if (this->GetContact (id).id >= 0)
			break;
		else
			std::cout<< "Empty contact slot,"<< std::endl;
	}
	PrintContact (this->GetContact (id));
	return;
}
