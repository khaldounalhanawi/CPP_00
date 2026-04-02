/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:02:34 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/02 10:02:35 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include <string>

Contact::Contact(void)
{
	this->id = -1;
	return;
};

Contact::~Contact()
{
	return;
};

std::string	Contact::GetField(int category) const
{
	return (this->_fields[category]);
};

void	Contact::SetField(int category, std::string content)
{
	this->_fields[category] = content;
};