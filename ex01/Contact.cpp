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