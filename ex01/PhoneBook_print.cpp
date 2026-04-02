/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_print.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:02:49 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/02 10:02:50 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "colors.hpp"

void	PrintSeperator(int ColumnCount, int ColumnWidth, bool edge)
{
	if (edge)
	{
		std::cout<< RESET
				 <<" "
				 << std::string((ColumnWidth * ColumnCount) + ColumnCount - 1, '-')
				 << " "
				 << std::endl;
		return;
	}
	while (ColumnCount)
	{
		std::cout<< RESET
				 << "|"
				 << std::string(ColumnWidth, '-');
		ColumnCount --;
	}
	std::cout<< RESET
			 << "|"
			 << std::endl;
}

void	PrintRow(int ColumnCount, int ColumnWidth, std::string *Content)
{
	std::string	SubString;
	int			i;

	i = 0;
	while (i < ColumnCount)
	{
		if ((int) Content[i].size () >= ColumnWidth)
			SubString = Content[i].substr (0, ColumnWidth - 1) + ".";
		else
			SubString = Content[i];
		std::cout<< RESET
				 << "|"
				 << std::setw (ColumnWidth)
				 << std::right
				 << SubString;
		i ++;
	}
	std::cout<< RESET
			 << "|"
			 << std::endl;
	return;
}

void	PrintTable(int ColumnCount, int ColumnWidth,
					const PhoneBook *book, std::string headers[])
{
	int	i;
	std::string content[ColumnCount];

	PrintSeperator (ColumnCount, ColumnWidth, true);
	PrintRow (ColumnCount, ColumnWidth, headers);
	i = 0;
	while (i < BookCapacity)
	{
		if (book->GetContact(i).id != -1)
		{
			PrintSeperator (ColumnCount, ColumnWidth, false);
			content[0] = book->GetContact(i).id + '0';
			content[1] = book->GetContact(i).GetField (0);
			content[2] = book->GetContact(i).GetField (1);
			content[3] = book->GetContact(i).GetField (2);
			PrintRow (ColumnCount, ColumnWidth, content);
		}
		i ++;
	}
	PrintSeperator (ColumnCount, ColumnWidth, true);
}

void	PrintContact(Contact contact)
{
	int	i;

	if (contact.id == -1)
		return;
	i = 0;
	while (i < CategoryCount)
	{
		std::cout<< RED
				 << names[i]
				 << ": "
				 << RESET;
		std::cout<< contact.GetField (i)<< std::endl;
		i ++;
	}
	return;
}
