#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
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
		std::cout<< "Please enter your "<< names[i]<< " :"<< std::endl;
		std::getline (std::cin, buffer);
		NewContact.SetField (i, buffer);
		i ++;
	}
	this->_ContactList[IndexPosition] = NewContact;
	std::cout<< "New contact has been saved!"<< std::endl;
	return;
}

void	PhoneBook::search(void) const
{
	int	i;
	int	j;

	i = 0;
	while (i < BookCapacity)
	{
		j = 0;
		while (j < CategoryCount)
		{
			if (this->_ContactList[i].GetField(j) == "")
				std::cout<< "[empty]"<< std::endl;
			else
				std::cout<< this->_ContactList[i].GetField(j) << std::endl;
			j ++;
		}
		std::cout<< "****************************"<< std::endl; // temp
		i ++;
	}
	return;
}

void	PhoneBook::ExitBook(void)
{
	return;
}