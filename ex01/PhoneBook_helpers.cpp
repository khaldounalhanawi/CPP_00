/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_helpers.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:02:44 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/02 10:02:45 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "colors.hpp"
#include <sstream>

bool	mini_stoi(std::string str, int &val, int maximum)
{
	std::stringstream	sstream(str);

	if (!(sstream >> val))
		return (false);
	if (!sstream.eof())
		return (false);
	if (val < 0 || val > maximum)
		return (false);
	else
		return (true);
}

int	GetIdInput(void)
{
	std::string	UserInput;
	bool		valid;
	int			RequestedId;

	std::cout	<< RESET
				<< "Please enter ID of the contact you'd like to explore:"
				<< std::endl;
	valid = false;
	while (!valid)
	{
		if (!std::getline (std::cin, UserInput))
			return (-2);
		if (!mini_stoi (UserInput, RequestedId, BookCapacity - 1))
			std::cout	<< "ID has to be between 0 and "
						<< BookCapacity
						<< "."
						<< std::endl;
		else
			valid = true;
	}
	return (RequestedId);
}
